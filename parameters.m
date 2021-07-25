clc;
close all;

T = 20;
step = 0.01; 


M1  = 2500; % kg - 1/4 car
M2 = 320; % kg - suspension mass


k1 = 80000;
k2 = 500000;

b1 = 350;
b2 = 15020;

K = [0 2.3e6 5e8 0 8e6]