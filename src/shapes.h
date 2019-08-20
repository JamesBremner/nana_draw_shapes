namespace nana
{

/** Draw shapes on a nana graph context

This class provides some primitive drawing shapes that are missing from nana::graph
and provides a consistent OOD wrapper for those that do

Implemented for Windows platform only.
*/
class shapes
{

public:

    /** CTOR
    @param[in] graph context
    */
    shapes( nana::paint::graphics& graph );

    /** Set color for drawings
        @param[in] color
    */
    void color(  const nana::color& color )
    {
        myColor = color;
    }

    /** Draw line
        @param[in] x1
        @param[in] y1
        @param[in] x2
        @param[in] y2
    */
    void line( int x1, int y1, int x2, int y2 );

    /** Draw circle
        @param[in] x0 x for center, pixels 0 at left of window
        @param[in] y0 y for center, pixels 0 at left of window
        @param[in] r radius, pixels
    */
    void circle( int x0, int y0, double r )
    {
        arc( x0, y0, r, 0, 0 );
    }

    /** Draw Arc of circle

        @param[in] x for conter, pixels 0 at left of window
        @param[in] y for center, pixels 0 at top of window
        @param[in] r radius, pixels
        @param[in] sa start angle degrees anti-clockwise from 3 o'clock
        @param[in] se end angle degrees anti-clockwise from 3 o'clock
    */
    void arc(
        int x, int y, double r,
        double sa, double ea );

    void rectangle( int xl, int yt, int xr, int yb  );

private:
    nana::paint::graphics& myGraph;
    nana::color myColor;
};
}

