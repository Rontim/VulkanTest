#include "first_app.hpp"

#include <iostream>
#include <stdexcept>

namespace lve
{

    FirstApp::FirstApp()
    {
        createPipelineLayout();
        createPipeline();
        createCommandBuffers();
    }

    FirstApp::~FirstApp()
    {
        vkDestroyPipelineLayout(lvedevice.device(), pipelineLayout, nullptr);
    }

    void FirstApp::run()
    {
        while (!lvewindow.shouldClose())
        {
            glfwPollEvents();
        }
    }

    void FirstApp::createPipelineLayout()
    {
        VkPipelineLayoutCreateInfo pipelineLayoutInfo{};
        pipelineLayoutInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
        pipelineLayoutInfo.setLayoutCount = 0;
        pipelineLayoutInfo.pSetLayouts = nullptr;

        if (vkCreatePipelineLayout(lvedevice.device(), &pipelineLayoutInfo, nullptr, &pipelineLayout) != VK_SUCCESS)
        {
            throw std::runtime_error("failed to create pipeline layout!");
        }
    }

    void FirstApp::createPipeline()
    {
        auto pipelineConfig = LvePipeline::defaultPipelineConfigInfo(lveswapchain.width(), lveswapchain.height());
        pipelineConfig.renderPass = lveswapchain.getRenderPass();
        pipelineConfig.pipelineLayout = pipelineLayout;

        lvepipeline = std::make_unique<LvePipeline>(lvedevice, "shaders/simple_shader.vert.spv", "shaders/simple_shader.frag.spv", pipelineConfig);
    }

    void FirstApp::createCommandBuffers() {}
    void FirstApp::drawFrame() {}

} // namespace lve