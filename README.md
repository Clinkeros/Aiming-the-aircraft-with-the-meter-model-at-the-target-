<h1>Aiming the aircraft with the meter model at the target</h1>
ЛА описывается следующими уравнениями:  
<p style="text-algin:center"> $$\frac{d\Theta}{dt}=\frac{g}{V}(n_{y_a}-\cos{\Theta}),$$  
$$\frac{dx}{dt}=V\cos{\Theta},$$  
$$\frac{dy}{dt}=V\sin{\Theta}.$$</p>  
Цель описывается следующими уравнениями:  
<p style="text-algin:center"> $$\frac{dx_ц}{dt}=V_ц\cos{\Theta_ц},$$  
$$\frac{dy_ц}{dt}=V_ц\sin{\Theta_ц}.$$  </p>  
<p>Модель измерителя заключается в накладывание шумов на величины $$r$$ и $$\varepsilon_ц$$. Шум моделируется с помощью алгоритма Бокса-Мюллера. Наложив шумы мы получаем измеренны значения $$r_{изм}$$ и $$\varepsilon_{ц~изм}$$:</p>  
<p style="text-algin:center">$$r_{изм}=r+\sigma_r\xi_r~,$$  
$$\varepsilon_{ц~изм}=\varepsilon_ц+\sigma_\varepsilon\xi_\varepsilon~,$$</p>  
<p>где $$\xi$$ – белый шум с нулевым математическим ожиданием и единичной дисперсией; $$\sigma$$ – значение дисперсии шумовой составляющей канала.</p>
<p>Ниже приведены примеры сигналов каналов измерителя без шума и с наложением шумов</p>  

![Пример без шумов](../Example/Examplre_without_noise.png)  
![Пример c шумами](../Example/Examplre_with_noise.png)
