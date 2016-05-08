#pragma once


class Round
{


private:

    double r;



public:


    /*
        描述  ： 初始化圆的半径为 r ;
    */
    Round(double r);


    /*
        描述  ： 设定圆的半径为 r ;
    */
    void SetR(double r);


    /*
        描述  ： 返回圆的面积；
    */
    double GetArea();


};

