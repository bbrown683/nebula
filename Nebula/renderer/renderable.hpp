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

#include <vector>
#include "thirdparty/glm/glm.hpp"

enum class ShaderStage {
    Fragment,
    Vertex,
};

struct Vertex {
	glm::fvec3 position;
	glm::fvec4 color;
};

/// This object contains most of the render-state associated with a single object.
/// This can include shaders, vertex buffers, index buffers, etc. It is associated 
/// with all of the command buffer/list generation.
class Renderable {
public:
	virtual ~Renderable() {}
    virtual bool build() = 0;
	virtual bool attachShader(const char* pFilename, ShaderStage stage) = 0;
	virtual bool setIndices(std::vector<uint16_t> indices) = 0;
	virtual bool setVertices(std::vector<Vertex> vertices) = 0;
};