#include <nana/gui.hpp>
#include <nana/gui/widgets/label.hpp>
#include <nana/gui/widgets/button.hpp>

int main()
{
    using namespace nana;

    form fm;
    fm.caption("Hello Nana");

    label lbl(fm, "Hello, Nana GUI!");
    lbl.move(rectangle{10, 10, 150, 30});

    button btn(fm, "Click me");
    btn.move(rectangle{10, 50, 100, 30});
    btn.events().click([&]{
        lbl.caption("Button clicked!");
    });

    fm.show();
    exec();
}
