function [y,yclean] = noise_signal(t)
    A=5;
    w=2*pi*10;
    sig=2.5;
    [n,m] = size(t);
    yclean = A*sin(w*t)+A/2*sin(w/2*t);
    y = yclean+sig*randn(n,m);