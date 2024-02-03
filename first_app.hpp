#pragma once

#include "live_window.hpp"
#include "lve_pipeline.hpp"
#include "lve_device.hpp"

namespace lve
{
    class FirstApp
    {
    public:
        static constexpr int WIDTH = 800;
        static constexpr int HEIGHT = 600;

        void run();

    private:
        LiveWindow lvewindow{WIDTH, HEIGHT, "Hello Traingle!"};
        LveDevice lvedevice{lvewindow};
        LvePipeline lvepipeline{
            lvedevice,
            "shaders/simple_shader.vert.spv",
            "shaders/simple_shader.frag.spv",
            LvePipeline::defaultPipelineConfigInfo(WIDTH, HEIGHT)};
    };

} // namespace lve
