clc;
clearvars;

theta = linspace(0, 2 .* pi, 500);
thetaRad = deg2rad(theta);

thetaX = linspace(0, 2 .* pi, 37);

subplot(2, 1, 1)
polarplot(theta, sin(2 * theta) .* cos(2 * theta), '-m')

subplot(2, 1, 2)
polarplot(thetaX, sin(thetaX), '-r*')

hold on

polarplot(thetaX, cos(thetaX), ':co')