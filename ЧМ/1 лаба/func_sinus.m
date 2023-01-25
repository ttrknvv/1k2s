x = sym("x");
f = sin(x) / (x + 1);
promezh = int(f, 2, 9);
disp('Area: '), disp(double(promezh));