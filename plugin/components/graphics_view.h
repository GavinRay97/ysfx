// Copyright 2021 Jean Pierre Cimalando
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// SPDX-License-Identifier: Apache-2.0
//

#pragma once
#include <juce_gui_basics/juce_gui_basics.h>

class YsfxGraphicsView : public juce::Component {
public:
    void configureGfx(int gfxWidth, int gfxHeight, bool gfxWantRetina);
    juce::Image &getBitmap() { return m_bitmap; }
    double getBitmapScale() const { return m_bitmapScale; }

protected:
    void paint(juce::Graphics &g) override;
    void resized() override;

private:
    void updateBitmap();

private:
    int m_gfxWidth = 0;
    int m_gfxHeight = 0;
    bool m_wantRetina = false;
    juce::Image m_bitmap{juce::Image::ARGB, 0, 0, false};
    double m_bitmapScale = 1;
    int m_bitmapUnscaledWidth = 0;
    int m_bitmapUnscaledHeight = 0;
};
