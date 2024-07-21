#include <iostream>
#include "ColorUtils.h"
#include "ColorNames.h"

namespace TelCoColorCoder {

    int numberOfMajorColors = sizeof(MajorColorNames) / sizeof(MajorColorNames[0]);
    int numberOfMinorColors = sizeof(MinorColorNames) / sizeof(MinorColorNames[0]);

    ColorPair GetColorFromPairNumber(int pairNumber) {
        int zeroBasedPairNumber = pairNumber - 1;
        MajorColor majorColor = static_cast<MajorColor>(zeroBasedPairNumber / numberOfMinorColors);
        MinorColor minorColor = static_cast<MinorColor>(zeroBasedPairNumber % numberOfMinorColors);
        return ColorPair(majorColor, minorColor);
    }

    int GetPairNumberFromColor(MajorColor major, MinorColor minor) {
        return major * numberOfMinorColors + minor + 1;
    }

    void PrintColorCodeManual() {
        for (int i = 1; i <= numberOfMajorColors * numberOfMinorColors; i++) {
            ColorPair colorPair = GetColorFromPairNumber(i);
            std::cout << i << ": " << colorPair.ToString() << std::endl;
        }
    }
}
