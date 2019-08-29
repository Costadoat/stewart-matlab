  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 5;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (Stewart_P)
    ;%
      section.nData     = 24;
      section.data(24)  = dumData; %prealloc
      
	  ;% Stewart_P.mapminmax_xmax
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Stewart_P.mapminmax_xmax_d3hx0fzg3v
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Stewart_P.mapminmax_xmax_i1mgu1wczb
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Stewart_P.mapminmax_xmax_aub2z1f52q
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Stewart_P.mapminmax1_xmax
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Stewart_P.mapminmax_xmax_ct4bepuicm
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Stewart_P.mapminmax_xmin
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Stewart_P.mapminmax_xmin_iehjoea5ea
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Stewart_P.mapminmax_xmin_cuaeahpuiv
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% Stewart_P.mapminmax_xmin_k4al5ovj24
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% Stewart_P.mapminmax1_xmin
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% Stewart_P.mapminmax_xmin_d0gqzccq3k
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% Stewart_P.mapminmax_ymax
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 12;
	
	  ;% Stewart_P.mapminmax_ymax_iej5kpatil
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 13;
	
	  ;% Stewart_P.mapminmax_ymax_jfea2ow0og
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 14;
	
	  ;% Stewart_P.mapminmax_ymax_ihor11sths
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 15;
	
	  ;% Stewart_P.mapminmax1_ymax
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 16;
	
	  ;% Stewart_P.mapminmax_ymax_lwlufp43xq
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 17;
	
	  ;% Stewart_P.mapminmax_ymin
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 18;
	
	  ;% Stewart_P.mapminmax_ymin_k5go5squy4
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 19;
	
	  ;% Stewart_P.mapminmax_ymin_ogggrkrg4e
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 20;
	
	  ;% Stewart_P.mapminmax_ymin_jjvvjjkkrv
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 21;
	
	  ;% Stewart_P.mapminmax1_ymin
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 22;
	
	  ;% Stewart_P.mapminmax_ymin_pwvv1lkczl
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 23;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 12;
      section.data(12)  = dumData; %prealloc
      
	  ;% Stewart_P.DigitalOutput_pinNumber
	  section.data(1).logicalSrcIdx = 24;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Stewart_P.PWM_pinNumber
	  section.data(2).logicalSrcIdx = 25;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Stewart_P.DigitalOutput_pinNum_ek4xiwztl1
	  section.data(3).logicalSrcIdx = 26;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Stewart_P.PWM_pinNumber_nkrnw2yx44
	  section.data(4).logicalSrcIdx = 27;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Stewart_P.DigitalOutput_pinNum_hetit3zm4v
	  section.data(5).logicalSrcIdx = 28;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Stewart_P.PWM_pinNumber_hoyrwcvift
	  section.data(6).logicalSrcIdx = 29;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Stewart_P.DigitalOutput_pinNum_bkde3yd3cq
	  section.data(7).logicalSrcIdx = 30;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Stewart_P.PWM_pinNumber_mx02rvdlnc
	  section.data(8).logicalSrcIdx = 31;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Stewart_P.DigitalOutput_pinNum_j5nhbsiy1k
	  section.data(9).logicalSrcIdx = 32;
	  section.data(9).dtTransOffset = 8;
	
	  ;% Stewart_P.PWM_pinNumber_cubsriyfnt
	  section.data(10).logicalSrcIdx = 33;
	  section.data(10).dtTransOffset = 9;
	
	  ;% Stewart_P.DigitalOutput_pinNum_p3klgfr0gp
	  section.data(11).logicalSrcIdx = 34;
	  section.data(11).dtTransOffset = 10;
	
	  ;% Stewart_P.PWM_pinNumber_n4eukf2fei
	  section.data(12).logicalSrcIdx = 35;
	  section.data(12).dtTransOffset = 11;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 63;
      section.data(63)  = dumData; %prealloc
      
	  ;% Stewart_P.Constant_Value
	  section.data(1).logicalSrcIdx = 36;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Stewart_P.theta_x_Value
	  section.data(2).logicalSrcIdx = 37;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Stewart_P.theta_y_Value
	  section.data(3).logicalSrcIdx = 38;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Stewart_P.theta_z_Value
	  section.data(4).logicalSrcIdx = 39;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Stewart_P.x_Value
	  section.data(5).logicalSrcIdx = 40;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Stewart_P.y_Value
	  section.data(6).logicalSrcIdx = 41;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Stewart_P.z_Value
	  section.data(7).logicalSrcIdx = 42;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Stewart_P.theta_x_Value_ekze1zr2o2
	  section.data(8).logicalSrcIdx = 43;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Stewart_P.theta_y_Value_hpy1hkark1
	  section.data(9).logicalSrcIdx = 44;
	  section.data(9).dtTransOffset = 8;
	
	  ;% Stewart_P.theta_z_Value_gi4rxypddg
	  section.data(10).logicalSrcIdx = 45;
	  section.data(10).dtTransOffset = 9;
	
	  ;% Stewart_P.x_Value_erhep10kxc
	  section.data(11).logicalSrcIdx = 46;
	  section.data(11).dtTransOffset = 10;
	
	  ;% Stewart_P.y_Value_au20vl24uo
	  section.data(12).logicalSrcIdx = 47;
	  section.data(12).dtTransOffset = 11;
	
	  ;% Stewart_P.z_Amp
	  section.data(13).logicalSrcIdx = 48;
	  section.data(13).dtTransOffset = 12;
	
	  ;% Stewart_P.z_Bias
	  section.data(14).logicalSrcIdx = 49;
	  section.data(14).dtTransOffset = 13;
	
	  ;% Stewart_P.z_Freq
	  section.data(15).logicalSrcIdx = 50;
	  section.data(15).dtTransOffset = 14;
	
	  ;% Stewart_P.z_Phase
	  section.data(16).logicalSrcIdx = 51;
	  section.data(16).dtTransOffset = 15;
	
	  ;% Stewart_P.Switch_Threshold
	  section.data(17).logicalSrcIdx = 52;
	  section.data(17).dtTransOffset = 16;
	
	  ;% Stewart_P.rm_Value
	  section.data(18).logicalSrcIdx = 53;
	  section.data(18).dtTransOffset = 17;
	
	  ;% Stewart_P.rf_Value
	  section.data(19).logicalSrcIdx = 54;
	  section.data(19).dtTransOffset = 18;
	
	  ;% Stewart_P.alpha_Value
	  section.data(20).logicalSrcIdx = 55;
	  section.data(20).dtTransOffset = 19;
	
	  ;% Stewart_P.beta_Value
	  section.data(21).logicalSrcIdx = 56;
	  section.data(21).dtTransOffset = 20;
	
	  ;% Stewart_P.h_Value
	  section.data(22).logicalSrcIdx = 57;
	  section.data(22).dtTransOffset = 21;
	
	  ;% Stewart_P.Lmin_Value
	  section.data(23).logicalSrcIdx = 58;
	  section.data(23).dtTransOffset = 22;
	
	  ;% Stewart_P.Lmax_Value
	  section.data(24).logicalSrcIdx = 59;
	  section.data(24).dtTransOffset = 23;
	
	  ;% Stewart_P.Gain6_Gain
	  section.data(25).logicalSrcIdx = 60;
	  section.data(25).dtTransOffset = 24;
	
	  ;% Stewart_P.Saturation_UpperSat
	  section.data(26).logicalSrcIdx = 61;
	  section.data(26).dtTransOffset = 25;
	
	  ;% Stewart_P.Saturation_LowerSat
	  section.data(27).logicalSrcIdx = 62;
	  section.data(27).dtTransOffset = 26;
	
	  ;% Stewart_P.Constant1_Value
	  section.data(28).logicalSrcIdx = 63;
	  section.data(28).dtTransOffset = 27;
	
	  ;% Stewart_P.Constant_Value_cxtxrspyx2
	  section.data(29).logicalSrcIdx = 64;
	  section.data(29).dtTransOffset = 28;
	
	  ;% Stewart_P.Lmin_Value_fxiqxw14ju
	  section.data(30).logicalSrcIdx = 65;
	  section.data(30).dtTransOffset = 29;
	
	  ;% Stewart_P.Lmax_Value_fp0qrty4ea
	  section.data(31).logicalSrcIdx = 66;
	  section.data(31).dtTransOffset = 30;
	
	  ;% Stewart_P.Gain1_Gain
	  section.data(32).logicalSrcIdx = 67;
	  section.data(32).dtTransOffset = 31;
	
	  ;% Stewart_P.Saturation_UpperSat_b3rn2kfzri
	  section.data(33).logicalSrcIdx = 68;
	  section.data(33).dtTransOffset = 32;
	
	  ;% Stewart_P.Saturation_LowerSat_bvomtudfti
	  section.data(34).logicalSrcIdx = 69;
	  section.data(34).dtTransOffset = 33;
	
	  ;% Stewart_P.Constant1_Value_cnehq0fw23
	  section.data(35).logicalSrcIdx = 70;
	  section.data(35).dtTransOffset = 34;
	
	  ;% Stewart_P.Constant_Value_dqqxjknpbv
	  section.data(36).logicalSrcIdx = 71;
	  section.data(36).dtTransOffset = 35;
	
	  ;% Stewart_P.Lmin_Value_d1kp3d2x14
	  section.data(37).logicalSrcIdx = 72;
	  section.data(37).dtTransOffset = 36;
	
	  ;% Stewart_P.Lmax_Value_nmppsrzwc4
	  section.data(38).logicalSrcIdx = 73;
	  section.data(38).dtTransOffset = 37;
	
	  ;% Stewart_P.Gain2_Gain
	  section.data(39).logicalSrcIdx = 74;
	  section.data(39).dtTransOffset = 38;
	
	  ;% Stewart_P.Saturation_UpperSat_dnbjpnjl05
	  section.data(40).logicalSrcIdx = 75;
	  section.data(40).dtTransOffset = 39;
	
	  ;% Stewart_P.Saturation_LowerSat_am0q0a0ygv
	  section.data(41).logicalSrcIdx = 76;
	  section.data(41).dtTransOffset = 40;
	
	  ;% Stewart_P.Constant1_Value_bzdab4one2
	  section.data(42).logicalSrcIdx = 77;
	  section.data(42).dtTransOffset = 41;
	
	  ;% Stewart_P.Constant_Value_ohnaqb1c5m
	  section.data(43).logicalSrcIdx = 78;
	  section.data(43).dtTransOffset = 42;
	
	  ;% Stewart_P.Lmin_Value_jjhk2iniiu
	  section.data(44).logicalSrcIdx = 79;
	  section.data(44).dtTransOffset = 43;
	
	  ;% Stewart_P.Lmax_Value_lhquxpnirq
	  section.data(45).logicalSrcIdx = 80;
	  section.data(45).dtTransOffset = 44;
	
	  ;% Stewart_P.Gain3_Gain
	  section.data(46).logicalSrcIdx = 81;
	  section.data(46).dtTransOffset = 45;
	
	  ;% Stewart_P.Saturation_UpperSat_llrmljpyl3
	  section.data(47).logicalSrcIdx = 82;
	  section.data(47).dtTransOffset = 46;
	
	  ;% Stewart_P.Saturation_LowerSat_ld4hzxvf1k
	  section.data(48).logicalSrcIdx = 83;
	  section.data(48).dtTransOffset = 47;
	
	  ;% Stewart_P.Constant1_Value_fhaxeoxakj
	  section.data(49).logicalSrcIdx = 84;
	  section.data(49).dtTransOffset = 48;
	
	  ;% Stewart_P.Constant3_Value
	  section.data(50).logicalSrcIdx = 85;
	  section.data(50).dtTransOffset = 49;
	
	  ;% Stewart_P.Lmin_Value_asz1pke2r5
	  section.data(51).logicalSrcIdx = 86;
	  section.data(51).dtTransOffset = 50;
	
	  ;% Stewart_P.Lmax_Value_nh4qnxlmtb
	  section.data(52).logicalSrcIdx = 87;
	  section.data(52).dtTransOffset = 51;
	
	  ;% Stewart_P.Gain4_Gain
	  section.data(53).logicalSrcIdx = 88;
	  section.data(53).dtTransOffset = 52;
	
	  ;% Stewart_P.Saturation1_UpperSat
	  section.data(54).logicalSrcIdx = 89;
	  section.data(54).dtTransOffset = 53;
	
	  ;% Stewart_P.Saturation1_LowerSat
	  section.data(55).logicalSrcIdx = 90;
	  section.data(55).dtTransOffset = 54;
	
	  ;% Stewart_P.Constant4_Value
	  section.data(56).logicalSrcIdx = 91;
	  section.data(56).dtTransOffset = 55;
	
	  ;% Stewart_P.Constant_Value_gamabtpgbn
	  section.data(57).logicalSrcIdx = 92;
	  section.data(57).dtTransOffset = 56;
	
	  ;% Stewart_P.Lmin_Value_iw11bz0kqi
	  section.data(58).logicalSrcIdx = 93;
	  section.data(58).dtTransOffset = 57;
	
	  ;% Stewart_P.Lmax_Value_pp0fbeghm2
	  section.data(59).logicalSrcIdx = 94;
	  section.data(59).dtTransOffset = 58;
	
	  ;% Stewart_P.Gain5_Gain
	  section.data(60).logicalSrcIdx = 95;
	  section.data(60).dtTransOffset = 59;
	
	  ;% Stewart_P.Saturation_UpperSat_dpja4mkxr2
	  section.data(61).logicalSrcIdx = 96;
	  section.data(61).dtTransOffset = 60;
	
	  ;% Stewart_P.Saturation_LowerSat_iddp3i1r04
	  section.data(62).logicalSrcIdx = 97;
	  section.data(62).dtTransOffset = 61;
	
	  ;% Stewart_P.Constant1_Value_kij2jw3212
	  section.data(63).logicalSrcIdx = 98;
	  section.data(63).dtTransOffset = 62;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% Stewart_P.Potentiomtre1_p1
	  section.data(1).logicalSrcIdx = 99;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Stewart_P.Potentiomtre2_p1
	  section.data(2).logicalSrcIdx = 100;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Stewart_P.Potentiomtre3_p1
	  section.data(3).logicalSrcIdx = 101;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Stewart_P.Potentiomtre4_p1
	  section.data(4).logicalSrcIdx = 102;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Stewart_P.Potentiomtre5_p1
	  section.data(5).logicalSrcIdx = 103;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Stewart_P.Potentiomtre6_p1
	  section.data(6).logicalSrcIdx = 104;
	  section.data(6).dtTransOffset = 5;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% Stewart_P.Gain1_Gain_jfd0ao4z3a
	  section.data(1).logicalSrcIdx = 105;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Stewart_P.Gain1_Gain_m20otgelwl
	  section.data(2).logicalSrcIdx = 106;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Stewart_P.Gain1_Gain_btfs54h4bx
	  section.data(3).logicalSrcIdx = 107;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Stewart_P.Gain1_Gain_ptftxodxyn
	  section.data(4).logicalSrcIdx = 108;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Stewart_P.Gain1_Gain_fpelshvuq5
	  section.data(5).logicalSrcIdx = 109;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Stewart_P.Gain1_Gain_j13fe42xcx
	  section.data(6).logicalSrcIdx = 110;
	  section.data(6).dtTransOffset = 5;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 2;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (Stewart_B)
    ;%
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% Stewart_B.L1
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Stewart_B.Add1
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Stewart_B.Gain6
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Stewart_B.Divide
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Stewart_B.Clock
	  section.data(5).logicalSrcIdx = 9;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Stewart_B.TmpSignalConversionAtsfunxyInpo
	  section.data(6).logicalSrcIdx = 10;
	  section.data(6).dtTransOffset = 5;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Stewart_B.DataTypeConversion
	  section.data(1).logicalSrcIdx = 11;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 0;
    sectIdxOffset = 2;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (Stewart_DW)
    ;%
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 2703431461;
  targMap.checksum1 = 3894138881;
  targMap.checksum2 = 1254058033;
  targMap.checksum3 = 3995045899;

