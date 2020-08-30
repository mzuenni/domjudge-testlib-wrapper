# domjudge-testlib-wrapper
A wrapper for the [testlib.h](https://github.com/MikeMirzayanov/testlib) to work with the [DOMjudge](https://www.domjudge.org/).
You only need to include ``domjudge.h`` instead of ``testlib.h``.
This header will redefine the exitcodes to ``42`` for AC submissions and ``43`` for WA submissin, as expected by DOMjudge.
Additionally it changes the functions ``registerTestlibCmd`` and ``registerInteraction`` to handle the parameters in ``argv`` correct.
