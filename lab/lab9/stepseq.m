function [f,k] = stepseq(k0, k1, k2, A)
    %f[k]=u(k-k0); k1<=k<=k2 
    k = [k1:k2];
    f = A*[k>=k0];
end

