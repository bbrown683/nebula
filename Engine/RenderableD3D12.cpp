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

#include "RenderableD3D12.hpp"
#include "DriverD3D12.hpp"

RenderableD3D12::RenderableD3D12(DriverD3D12* pDriver) : m_pDriver(pDriver) {}

bool RenderableD3D12::attachShader(const char* pFilename, ShaderStage stage) {
    const char* pBlobName = std::strcat(const_cast<char*>(pFilename), ".cso");
    const char* target;
    switch (stage) {
    case ShaderStage::Fragment: target = "ps_5_0"; break;
    case ShaderStage::Geometry: target = "gs_5_0"; break;
    case ShaderStage::TesselationControl: target = "hs_5_0"; break;
    case ShaderStage::TesselationEvaluation: target = "ds_5_0"; break;
    case ShaderStage::Vertex: target = "vs_5_0"; break;
    }
    wchar_t pBlobNameWide[64];
    size_t length = std::mbstowcs(pBlobNameWide, pBlobName, 64);
    if (length != -1)
        pBlobNameWide[length] = '\0';
    
    ID3DBlob* pBlob;
    if (FAILED(D3DReadFileToBlob(pBlobNameWide, &pBlob)))
        return false;
    m_pBlobs.push_back(std::move(pBlob));
    return true;
}

bool RenderableD3D12::execute() {
    return false;
}

bool RenderableD3D12::setIndexBuffer(std::vector<uint16_t> indices) {
    return false;
}

bool RenderableD3D12::setVertexBuffer(std::vector<uint32_t> vertices) {
    return false;
}
