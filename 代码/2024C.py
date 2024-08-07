# -*- coding: utf-8 -*-
"""
Created on Mon Jul 29 08:21:11 2024

@author: hp
"""

import numpy as np
import matplotlib.pyplot as plt

t=np.linspace(0, 0.000001,10000000)

def AM_sig(carrier_freq_,modu_freq_,gain_,depth_,a_,t_,sita_):
    carrier_w = 2*np.pi*carrier_freq_
    modu_w = 2*np.pi*modu_freq_
    orig=gain_*(1+depth_*np.cos(t*modu_w))*np.cos(t*carrier_w)
    delay=gain_*(1+depth_*np.cos(t*modu_w))*np.cos(t*carrier_w)
    
    
    return orig+delay
    


am_sig=AM_sig(40e6,2e6,1,0.5)
plt.plot(am_sig)
