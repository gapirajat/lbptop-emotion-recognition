#include "uniform_pattern.h"

#include <bitset>

#include <QString>

#include "global.h"

#define ELEM(start, xpos) *((int*)(start + (xpos) * sizeof(int)))

UniformPattern::UniformPattern() {}

UniformPattern::~UniformPattern() {}

/*
@laod Uniform Pattern.
@Example:
@      uniform_pattern_8bits.xml.
*/
void UniformPattern::LoadUniformPattern()
{
    FileStorage fs;
    QString pattern_file = Uniform_Pattern_File_Dir"uniform_pattern_" + QString::number(g_Pxy) + "bits.xml";
    fs.open(pattern_file.toLocal8Bit().toStdString(), FileStorage::READ);
    if (!fs.isOpened())
    {
        return;
    }
    bits_ = (int)fs["bits_"];
    fs["uniformPattern"] >> uniform_pattern_;
    fs.release();
}

/*
@Uniform pattern dimensionality reduction.
@Input parameters: V, the feature value to be reduced.
@Output: None.
@Return value: The value of V after dimensionality reduction (-1 indicates that V is a non-equivalent mode class)
*/
int UniformPattern::IndexOf(const unsigned V)
{
    int begin = 0;
    int end = uniform_pattern_.cols - 1;
    while (begin <= end)
    {
        int mid = (begin + end) / 2;
        int x = ELEM(uniform_pattern_.data, mid);
        if (x == int(V))
        {
            return mid;
        }
        else if (x > int(V))
        {
            end = mid - 1;
        }
        else
        {
            begin = mid + 1;
        }
    }
    return -1; /*-1 means V is a non-equivalence class*/
}
