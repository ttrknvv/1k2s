%Вариант 9
clear
clc
X = [-2.00 -1.30 -0.65 0.19 1.50 1.60 1.80 3.70 3.30 4.20]; 
Y =[1.20 2.10 3.80 5.60 4.70 2.70 1.60 0.95 0.64 0.45];
n = length (X);
 plot (X, Y)
 grid on
Sx = sum(X);
Sx2 = sum(X.^2);
Sx3 = sum(X.^3);
Sx4 = sum(X.^4);
%производим замену переменных
Sumy = sum(1./Y);
Sumxy = sum(X./Y);
Sumx2y = sum(X.^2./Y);
% t = x
% z = 1/y
% n*a0 + St*a1 + St2*a2 = Sz
% St*a0 + St2*a1 + St3*a2 = Stz
% St2*a0 + St3*a1 + St4*a2 = St2z 

MNK = [ n Sx Sx2;   
        Sx Sx2 Sx3;
        Sx2 Sx3 Sx4;]

b =[Sumy;
    Sumxy;
    Sumx2y;]
% расчет корней
X0 = MNK\b %метод Гаусса
a0 = X0(1)
a1 = X0(2)
a2 = X0(3)

x = linspace(X(1),X(10)); %генерирует 100 точек, равномерно распределенных в интервале от а до b.
Func = 1./(a0 + a1*x + a2*x.^2);
hold on
plot(x,Func)
hold on
legend('Функция','1 /(a0 + a1 * x + a2 * x^2)')

%среднеквадратичная ошибка (RMSE – root-mean-square error)
RMSE2 =0;
Summarazn =0;
i=1;
while i < n 
    Summarazn = Summarazn + (Y(i)- Func(i)).^2;
    i = i+1;
end
RMSE2 = sqrt(Summarazn./n)