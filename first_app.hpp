#pragma once

#include "live_window.hpp"
#include "lve_pipeline.hpp"
#include "lve_device.hpp"
#include "lve_swap_chain.hpp"

#include <memory>
#include <vector>

namespace lve
{
    class FirstApp
    {
    public:
        static constexpr int WIDTH = 800;
        static constexpr int HEIGHT = 600;

        FirstApp();
        ~FirstApp();

        FirstApp(const FirstApp &) = delete;
        FirstApp &operator=(const FirstApp &) = delete;

        void run();

    private:
        void createPipelineLayout();
        void createPipeline();
        void createCommandBuffers();
        void drawFrame();

        LiveWindow lvewindow{WIDTH, HEIGHT, "Hello Traingle!"};
        LveDevice lvedevice{lvewindow};
        LveSwapChain lveswapchain{lvedevice, lvewindow.getExtent()};

        std::unique_ptr<LvePipeline> lvepipeline;
        VkPipelineLayout pipelineLayout;
        std::vector<VkCommandBuffer> commandBuffers;
    };

} // namespace lve
