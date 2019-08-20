#include <nana/gui.hpp>

#include <cmath>
#include <nana/gui.hpp>

#include <windows.h>

#include "shapes.h"

static HDC myHDC;

namespace nana
{
shapes::shapes( nana::paint::graphics& graph )
    : myGraph( graph )
{
    myHDC = reinterpret_cast<HDC>(const_cast<void*>(graph.context()));
}
void shapes::line( int x1, int y1, int x2, int y2 )
{
    myGraph.line(
        nana::point(x1,y1),
        nana::point(x2,y2),
        myColor );
}
void shapes::rectangle( int xl, int yt, int xr, int yb  )
{
    myGraph.rectangle(
    { xl, yt, xr, yb },
    false,
    myColor );
}
void shapes::arc(
    int x, int y, double r,
    double sa, double ea )
{
    int xl =round( x-r );
    int yt =round( y-r );
    int xr =round( x+r );
    int yb =round( y+r );
    int xs =round( x + r * cos(sa * M_PI/180) );
    int ys =round( y + r * sin(sa * M_PI/180) );
    int xe =round( x + r * cos(ea * M_PI/180) );
    int ye =round( y + r * sin(ea * M_PI/180) );

    HDC hdc = reinterpret_cast<HDC>(const_cast<void*>(myGraph.context()));
    SelectObject(hdc, GetStockObject(DC_PEN));
    SetDCPenColor(hdc, RGB(myColor.r(),myColor.g(),myColor.b()));
    Arc(
        hdc,
        xl,yt,xr,yb,xs,ys,xe,ye );
}
}
