function f = rectpuls_para(t, w, A, tau, T0, w0) 
    f = A*(t>=-0.5*tau+T0 & t<=0.5*tau+T0).*exp(-j*(w-w0)*t);
end

% A   : amplitude
% tau : signal width
% T0  : timing right shift
% w0  : frequence right shift