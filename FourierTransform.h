#pragma once

#include "OceanDefine.h"

#include <Blast/Gfx/GfxDefine.h>
#include <Blast/Gfx/GfxDevice.h>

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>

class FourierTransform {
public:
    FourierTransform(Context* context, int size);

    ~FourierTransform();

    void Execute(blast::GfxCommandBuffer* cmd, blast::GfxTexture* in, blast::GfxTexture* out);

private:
    struct LookUp {
        int j1, j2;
        float wr, wi;
    };

private:
    int size = 0;
    int passes = 0;
    Context* context = nullptr;
    blast::GfxTexture* pass_texture0 = nullptr;
    blast::GfxTexture* pass_texture1 = nullptr;
    blast::GfxBuffer* butterfly_lookup_table = nullptr;
};