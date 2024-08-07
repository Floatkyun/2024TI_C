# -*- coding: utf-8 -*-
"""
Created on Tue Jul 30 17:15:26 2024

@author: hp
"""
import numpy as np 
def cal_Phase(t_,freq):#//t_:ns ;freq:MHz
	delay_t=t_/1000.0;
	Freq=freq;
	T_=1.0/Freq
	
	t_eq = np.mod(delay_t,T_);
	return t_eq*360.0/T_;

cal_Phase(500, 40)

