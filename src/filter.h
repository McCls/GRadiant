/**
   Copyright (c) 2016 FirstBuild - All Rights Reserved

*/

//Low pass bessel filter order=3 alpha1=.125 
class  FilterBeLp3
{
  public:
    FilterBeLp3()
   {
      v[0] = 0.0;
      v[1] = 0.0;
    }
  private:
    float v[3];
  public:
    float step(float x) //class II
    {
      v[0] = v[1];
      v[1] = v[2];
      v[2] = (9.810514574132291022e-5 * x)
             + (-0.96598348806398948163 * v[0])
             + (1.96559106748102419004 * v[1]);
      return
        (v[0] + v[2])
        + 2 * v[1];
    }
};
