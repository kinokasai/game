#include "palette.hh"

void make_classic(std::vector<color>& colors)
{
    colors.push_back(make_color_hex(0xD3D3D3));
    colors.push_back(make_color_hex(0x323232));
    colors.push_back(make_color(0, .6f, .8f));
    colors.push_back(make_color(.8f, 0.f, .2f));
    colors.push_back(make_color_hex(0xD15FEE));
}

void make_gb(std::vector<color>& colors)
{
    colors.push_back(make_color_hex(0x9BBC0F));
    colors.push_back(make_color_hex(0x0F380F));
    colors.push_back(make_color_hex(0x306230));
    colors.push_back(make_color_hex(0x306230));
    colors.push_back(make_color_hex(0x306230));
}

std::vector<color> make_palettes()
{
    std::vector<color> colors;
    make_classic(colors);
    make_gb(colors);
    return colors;
}

color get_color(int idx, state& state)
{
    return state.palette_colors[idx + state.palette * 5];
}
