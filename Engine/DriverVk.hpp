/*
MIT License

Copyright (c) 2018 Ben Brown

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#pragma once

#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#define VK_USE_PLATFORM_WIN32_KHR
#define VULKAN_HPP_NO_EXCEPTIONS
#include <vulkan/vulkan.hpp>

#include "Driver.hpp"

class DriverVk : public Driver {
public:
    DriverVk(GLFWwindow* pWindow);

    // Inherited via IDriver
    bool initialize() override;
    bool selectGpu(uint8_t id) override;
    void submit() override;
    std::unique_ptr<Renderable> createRenderable(bool once) override;

    vk::UniqueDevice& getDevice();
    vk::UniqueSwapchainKHR& getSwapchain();
private:
    vk::UniqueInstance m_pInstance;
    std::vector<vk::PhysicalDevice> m_PhysicalDevices;
    vk::UniqueSurfaceKHR m_pSurface;
    vk::UniqueDevice m_pDevice;
    vk::UniqueFence m_pFence;
    vk::UniqueSwapchainKHR m_pSwapchain;

    bool anisotropy;
    float maxAnisotropy;
};