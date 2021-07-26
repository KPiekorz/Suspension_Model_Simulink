function [x_k1, y_k1] = suspension_step(x_k, u, h, m1, m2, k1, k2, b1, b2)

%suspension_step Return another step of simulation using euler method

    A=[0                 1   0                                              0
       -(b1*b2)/(m1*m2)  0   ((b1/m1)*((b1/m1)+(b1/m2)+(b2/m2)))-(k1/m1)    -(b1/m1)
       b2/m2             0  -((b1/m1)+(b1/m2)+(b2/m2))                      1
       k2/m2             0  -((k1/m1)+(k1/m2)+(k2/m2))                      0];

    B=[0                 0
       1/m1              (b1*b2)/(m1*m2)
       0                -(b2/m2)
       (1/m1)+(1/m2)    -(k2/m2)];

    C=[0 0 1 0];

    D=[0 0];
    
    dx = A*x_k + B*u;
    x_k1 = x_k + dx*h;
    y_k1 = C*x_k1 + D*u;
    
end

