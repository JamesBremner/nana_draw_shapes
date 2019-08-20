# nanaShapes
 
 Draw shapes on a nana graph context

This class provides some primitive drawing shapes that are missing from nana::graph
( specifically circles and arcs )
and provides a consistent OOD wrapper for those that do

Implemented for Windows platform only.

```
#include <nana/gui.hpp>

#include "shapes.h"

int main()
{
    nana::form f;
    f.bgcolor( nana::colors::black );

    nana::drawing dw{f};
    dw.draw([](nana::paint::graphics& graph)
    {
        nana::shapes S( graph );
        S.color( nana::colors::yellow );

        int y = 10;
        S.line( 100, y, 200, y );

        y += 20;
        S.circle( 80, y+30, 15 );
        S.circle( 200, y+30, 15 );

        y += 50;
        S.arc(
            150, y+100,
            100,
            315, 225            // from 'ten past' to 'ten to'
        );

        S.color( nana::colors::white );
        S.rectangle( 5, 5, 280, 180 );

    });

    f.show();
    nana::exec();
}
```

