#ifndef COLORPIXEL_H
#define COLORPIXEL_H

class ColorPixel{
private:
    int redValue;
    int blueValue;
    int greenValue;

public:
    ColorPixel(int redValue, int blueValue, int greenValue);
    ~ColorPixel();
    int getRedValue();
    int getBlueValue();
    int getGreenValue();

};

#endif // COLORPIXEL_H
