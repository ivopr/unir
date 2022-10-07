function T = otsu(img)
pkg load image;

h = imhist(img, 256);
p = h / sum(h);
omega = cumsum(p);
mu = cumsum(p .* [1:256]');

muT = mu(end);

sigmaB = (muT .* omega - mu).^2 ./ (omega .* (1 - omega));
m = max(sigmaB);
T = mean(find(sigmaB == m));

im2bw(img, T / 255);
endfunction
