/*
@Uniform Pattern, 原始特征数据降维.
*/
#ifndef UNIFORM_PATTERN_H
#define UNIFORM_PATTERN_H

#include <opencv2/opencv.hpp>

using namespace cv;

class UniformPattern
{
public:
    UniformPattern();
    virtual ~UniformPattern();

    void LoadUniformPattern();      /*Load Uniform Pattern.*/
    int IndexOf(const unsigned V);  /*Uniform Pattern Dimensionality Reduction.*/

private:
    Mat uniform_pattern_;           /*Equivalent pattern sequence, data are all equivalent pattern classes*/
    int bits_;                      /*Number of sampling points*/
};

#endif /*UNIFORM_PATTERN_H*/
