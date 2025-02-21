#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#define assertm(exp, msg) assert(((void)msg, exp))

using namespace std;


class Box
{
public:
    unsigned length, width, height;

    Box()
        : length(0), width(0), height(0)
    {}

    Box(unsigned length, unsigned width, unsigned height)
    {
        this->length = length;
        this->width = width;
        this->height = height;
    }

    Box(Box &box)
    {
        this->length = box.length;
        this->width = box.width;
        this->height = box.height;
    }

    Box &
    operator=(Box const &box)
    {
        length = box.length;
        width = box.width;
        height = box.height;
        return *this;
    }

    unsigned
    getVolume() const
    {
        return length * width * height;
    }

    void
    scale(unsigned scaleValue)
    {
        length *= scaleValue;
        width *= scaleValue;
        height *= scaleValue;
    }

    bool
    isBigger(Box &other) const
    {
        return getVolume() >= other.getVolume();
    }

    bool
    isSmaller(Box &other) const
    {
        return getVolume() <= other.getVolume();
    }

    Box
    operator*(unsigned scaleValue) const
    {
        return {scaleValue * length, scaleValue * width, scaleValue * height};
    }

    bool
    operator==(Box &other)
    {
        vector<unsigned> v1 = {length, width, height};
        vector<unsigned> v2 = {other.length, other.width, other.height};
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());

        return v1 == v2;
    }
};

class Cube
{
public:
    unsigned a;

    Cube()
        : a(0)
    {}

    Cube(unsigned a)
    {
        this->a = a;
    }

    operator Box() const
    {
        return {a, a, a};
    }
};

int
main()
{
    // BEG: Task 1
    unsigned smallBoxDims[] = {1, 2, 3};
    unsigned mediumBoxDims[] = {4, 5, 6};
    unsigned scaleVal = 2;
    Box zeroBox; // default
    Box smallBox{smallBoxDims[0], smallBoxDims[1], smallBoxDims[2]}; // conversion
    Box mediumBox{mediumBoxDims[0], mediumBoxDims[1], mediumBoxDims[2]}; // conversion
    Box anotherMediumBox{mediumBox}; // copy
    anotherMediumBox = mediumBox; // assignment operator

    assertm(zeroBox.length == 0 && zeroBox.width == 0 && zeroBox.height == 0,
            "Checkpoint #1: zeroBox (default) sides are zero");
    // END: Task 1

    // BEG: Task 2
    unsigned smallVol = smallBoxDims[0] * smallBoxDims[1] * smallBoxDims[2];
    unsigned mediumVol = mediumBoxDims[0] * mediumBoxDims[1] * mediumBoxDims[2];

    assertm(smallBox.getVolume() == smallVol, "Checkpoint #2: verify smallBox volume");
    assertm(mediumBox.getVolume() == mediumVol, "Checkpoint #3: verify mediumBox volume");

    Box anotherMediumBoxScaled = anotherMediumBox;
    anotherMediumBoxScaled.scale(scaleVal);
    assertm(
        anotherMediumBoxScaled.length == mediumBoxDims[0] * scaleVal
            && anotherMediumBoxScaled.width == mediumBoxDims[1] * scaleVal
            && anotherMediumBoxScaled.height == mediumBoxDims[2] * scaleVal,
        "Checkpoint #4: anotherMediumBox scale works");

    assertm(mediumBox.isBigger(smallBox), "Checkpoint #5: bigBox mediumBox than smallBox");
    assertm(!anotherMediumBox.isSmaller(smallBox), "Checkpoint #6: anotherMediumBox NOT isSmaller than smallBox");
    // END: Task 2

    // BEG: Task 3
    unsigned bigBoxDims[] = {7, 8, 9};
    Box bigBox{bigBoxDims[0], bigBoxDims[1], bigBoxDims[2]};
    Box anotherBigBoxShuffled{bigBoxDims[2], bigBoxDims[0], bigBoxDims[1]};
    Box bigBoxScaled = bigBox * scaleVal;

    assertm(bigBoxScaled.length == bigBoxDims[0] * scaleVal && bigBoxScaled.width == bigBoxDims[1] * scaleVal
                && bigBoxScaled.height == bigBoxDims[2] * scaleVal,
            "Checkpoint #7: bigBox equals anotherBigBoxShuffled");

    assertm(bigBox == anotherBigBoxShuffled, "Checkpoint #8: bigBox equals anotherBigBoxShuffled");
    assertm(!(bigBox == mediumBox), "Checkpoint #9: bigBox is not equal to mediumBox");

    // END: Task 3

    // BEG: Task 4
    unsigned cubeSide = 5;
    Cube cube{cubeSide};
    Box boxFromCube = cube;
    assertm(boxFromCube.length == cubeSide && boxFromCube.width == cubeSide && boxFromCube.height == cubeSide,
            "Checkpoint #10: boxFromCube");

    // END: Task 4

    cout << "Everything run successfully!" << endl;
    return 0;
}
