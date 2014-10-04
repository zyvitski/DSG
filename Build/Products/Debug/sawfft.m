%Fourier Transform of Sound File 

%Load File 
setenv('GNUTERM','aqua')
file = '~/Documents/DSG/Build/Products/Debug/sndfile.wav'; 
[y,Fs,bits] = wavread(file); 

Nsamps = length(y); 
t = (1/Fs)*(1:Nsamps);          %Prepare time data for plot 

%Do Fourier Transform 
y_fft = abs(fft(y));            %Retain Magnitude 
y_fft = y_fft(1:Nsamps/2);      %Discard Half of Points 
f = Fs*(0:Nsamps/2-1)/Nsamps;   %Prepare freq data for plot 
ymax = max(y_fft);

%Plot Sound File in Time Domain 
figure 
plot(t, y);
ylim([-1,1])
xlim([0,0.1])
xlabel('Time (s)') 
ylabel('Amplitude') 
title('Waveform')
grid();


%Plot Sound File in Frequency Domain 
figure 

plot(f, y_fft); 
xlim([1, Fs])
ylim([0.01,ymax*1.5])
set(gca,'xscale','log')
set(gca,'yscale','log')
grid();
xlabel('Frequency (Hz)') 
ylabel('Amplitude') 
title('Frequency Response')

