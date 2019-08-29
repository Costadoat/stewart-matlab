function RTW_Sid2UrlHash() {
	this.urlHashMap = new Array();
	/* <Root>/theta_x */
	this.urlHashMap["untitled:11"] = "untitled.c:130,135,223&untitled.h:220&untitled_data.c:56";
	/* <S1>/Abs */
	this.urlHashMap["untitled:3"] = "untitled.c:196";
	/* <S1>/Saturation */
	this.urlHashMap["untitled:4"] = "untitled.c:153,162&untitled.h:229,232&untitled_data.c:65,68";
	/* <S1>/Sign */
	this.urlHashMap["untitled:5"] = "untitled.c:164,179";
	/* <S2>/Data Type Conversion */
	this.urlHashMap["untitled:9:114"] = "untitled.c:166,169,172,175,181";
	/* <S2>/Digital Output */
	this.urlHashMap["untitled:9:214"] = "untitled.c:192,318&untitled.h:214&untitled_data.c:50";
	/* <S3>/Derivative Gain */
	this.urlHashMap["untitled:12:1650"] = "untitled.c:134&untitled.h:149,186&untitled_data.c:22";
	/* <S3>/Filter */
	this.urlHashMap["untitled:12:1652"] = "untitled.c:141,261,327&untitled.h:157,163,169,226&untitled_data.c:62";
	/* <S3>/Filter Coefficient */
	this.urlHashMap["untitled:12:1653"] = "untitled.c:140&untitled.h:150,192&untitled_data.c:28";
	/* <S3>/Integral Gain */
	this.urlHashMap["untitled:12:1649"] = "untitled.c:222&untitled.h:151,189&untitled_data.c:25";
	/* <S3>/Integrator */
	this.urlHashMap["untitled:12:1651"] = "untitled.c:148,258,324&untitled.h:156,162,168,223&untitled_data.c:59";
	/* <S3>/Proportional Gain */
	this.urlHashMap["untitled:12:1648"] = "untitled.c:129&untitled.h:148,195&untitled_data.c:31";
	/* <S3>/Sum */
	this.urlHashMap["untitled:12:1647"] = "untitled.c:147";
	/* <S3>/SumD */
	this.urlHashMap["untitled:12:1654"] = "untitled.c:142";
	/* <S4>/Data Type Conversion */
	this.urlHashMap["untitled:10:114"] = "untitled.c:199,217";
	/* <S4>/PWM */
	this.urlHashMap["untitled:10:215"] = "untitled.c:219,321&untitled.h:217&untitled_data.c:53";
	/* <S5>/Add min y */
	this.urlHashMap["untitled:6:846"] = "untitled.c:200&untitled.h:210&untitled_data.c:46";
	/* <S5>/Subtract min x */
	this.urlHashMap["untitled:6:847"] = "untitled.c:201&untitled.h:202&untitled_data.c:38";
	/* <S5>/range y // range x */
	this.urlHashMap["untitled:6:848"] = "untitled.c:202&untitled.h:198,203,206,211&untitled_data.c:34,39,42,47";
	this.getUrlHash = function(sid) { return this.urlHashMap[sid];}
}
RTW_Sid2UrlHash.instance = new RTW_Sid2UrlHash();
function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "untitled"};
	this.sidHashMap["untitled"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<S1>"] = {sid: "untitled:1"};
	this.sidHashMap["untitled:1"] = {rtwname: "<S1>"};
	this.rtwnameHashMap["<S2>"] = {sid: "untitled:9"};
	this.sidHashMap["untitled:9"] = {rtwname: "<S2>"};
	this.rtwnameHashMap["<S3>"] = {sid: "untitled:12"};
	this.sidHashMap["untitled:12"] = {rtwname: "<S3>"};
	this.rtwnameHashMap["<S4>"] = {sid: "untitled:10"};
	this.sidHashMap["untitled:10"] = {rtwname: "<S4>"};
	this.rtwnameHashMap["<S5>"] = {sid: "untitled:6"};
	this.sidHashMap["untitled:6"] = {rtwname: "<S5>"};
	this.rtwnameHashMap["<Root>/Adaptation1"] = {sid: "untitled:1"};
	this.sidHashMap["untitled:1"] = {rtwname: "<Root>/Adaptation1"};
	this.rtwnameHashMap["<Root>/Digital Output"] = {sid: "untitled:9"};
	this.sidHashMap["untitled:9"] = {rtwname: "<Root>/Digital Output"};
	this.rtwnameHashMap["<Root>/PID1"] = {sid: "untitled:12"};
	this.sidHashMap["untitled:12"] = {rtwname: "<Root>/PID1"};
	this.rtwnameHashMap["<Root>/Vérin 1"] = {sid: "untitled:10"};
	this.sidHashMap["untitled:10"] = {rtwname: "<Root>/Vérin 1"};
	this.rtwnameHashMap["<Root>/theta_x"] = {sid: "untitled:11"};
	this.sidHashMap["untitled:11"] = {rtwname: "<Root>/theta_x"};
	this.rtwnameHashMap["<S1>/ecart"] = {sid: "untitled:2"};
	this.sidHashMap["untitled:2"] = {rtwname: "<S1>/ecart"};
	this.rtwnameHashMap["<S1>/Abs"] = {sid: "untitled:3"};
	this.sidHashMap["untitled:3"] = {rtwname: "<S1>/Abs"};
	this.rtwnameHashMap["<S1>/Saturation"] = {sid: "untitled:4"};
	this.sidHashMap["untitled:4"] = {rtwname: "<S1>/Saturation"};
	this.rtwnameHashMap["<S1>/Sign"] = {sid: "untitled:5"};
	this.sidHashMap["untitled:5"] = {rtwname: "<S1>/Sign"};
	this.rtwnameHashMap["<S1>/mapminmax"] = {sid: "untitled:6"};
	this.sidHashMap["untitled:6"] = {rtwname: "<S1>/mapminmax"};
	this.rtwnameHashMap["<S1>/sens"] = {sid: "untitled:7"};
	this.sidHashMap["untitled:7"] = {rtwname: "<S1>/sens"};
	this.rtwnameHashMap["<S1>/pwm"] = {sid: "untitled:8"};
	this.sidHashMap["untitled:8"] = {rtwname: "<S1>/pwm"};
	this.rtwnameHashMap["<S2>/In1"] = {sid: "untitled:9:116"};
	this.sidHashMap["untitled:9:116"] = {rtwname: "<S2>/In1"};
	this.rtwnameHashMap["<S2>/Data Type Conversion"] = {sid: "untitled:9:114"};
	this.sidHashMap["untitled:9:114"] = {rtwname: "<S2>/Data Type Conversion"};
	this.rtwnameHashMap["<S2>/Digital Output"] = {sid: "untitled:9:214"};
	this.sidHashMap["untitled:9:214"] = {rtwname: "<S2>/Digital Output"};
	this.rtwnameHashMap["<S3>/u"] = {sid: "untitled:12:1"};
	this.sidHashMap["untitled:12:1"] = {rtwname: "<S3>/u"};
	this.rtwnameHashMap["<S3>/Derivative Gain"] = {sid: "untitled:12:1650"};
	this.sidHashMap["untitled:12:1650"] = {rtwname: "<S3>/Derivative Gain"};
	this.rtwnameHashMap["<S3>/Filter"] = {sid: "untitled:12:1652"};
	this.sidHashMap["untitled:12:1652"] = {rtwname: "<S3>/Filter"};
	this.rtwnameHashMap["<S3>/Filter Coefficient"] = {sid: "untitled:12:1653"};
	this.sidHashMap["untitled:12:1653"] = {rtwname: "<S3>/Filter Coefficient"};
	this.rtwnameHashMap["<S3>/Integral Gain"] = {sid: "untitled:12:1649"};
	this.sidHashMap["untitled:12:1649"] = {rtwname: "<S3>/Integral Gain"};
	this.rtwnameHashMap["<S3>/Integrator"] = {sid: "untitled:12:1651"};
	this.sidHashMap["untitled:12:1651"] = {rtwname: "<S3>/Integrator"};
	this.rtwnameHashMap["<S3>/Proportional Gain"] = {sid: "untitled:12:1648"};
	this.sidHashMap["untitled:12:1648"] = {rtwname: "<S3>/Proportional Gain"};
	this.rtwnameHashMap["<S3>/Sum"] = {sid: "untitled:12:1647"};
	this.sidHashMap["untitled:12:1647"] = {rtwname: "<S3>/Sum"};
	this.rtwnameHashMap["<S3>/SumD"] = {sid: "untitled:12:1654"};
	this.sidHashMap["untitled:12:1654"] = {rtwname: "<S3>/SumD"};
	this.rtwnameHashMap["<S3>/y"] = {sid: "untitled:12:10"};
	this.sidHashMap["untitled:12:10"] = {rtwname: "<S3>/y"};
	this.rtwnameHashMap["<S4>/In1"] = {sid: "untitled:10:116"};
	this.sidHashMap["untitled:10:116"] = {rtwname: "<S4>/In1"};
	this.rtwnameHashMap["<S4>/Data Type Conversion"] = {sid: "untitled:10:114"};
	this.sidHashMap["untitled:10:114"] = {rtwname: "<S4>/Data Type Conversion"};
	this.rtwnameHashMap["<S4>/PWM"] = {sid: "untitled:10:215"};
	this.sidHashMap["untitled:10:215"] = {rtwname: "<S4>/PWM"};
	this.rtwnameHashMap["<S5>/x"] = {sid: "untitled:6:845"};
	this.sidHashMap["untitled:6:845"] = {rtwname: "<S5>/x"};
	this.rtwnameHashMap["<S5>/Add min y"] = {sid: "untitled:6:846"};
	this.sidHashMap["untitled:6:846"] = {rtwname: "<S5>/Add min y"};
	this.rtwnameHashMap["<S5>/Subtract min x"] = {sid: "untitled:6:847"};
	this.sidHashMap["untitled:6:847"] = {rtwname: "<S5>/Subtract min x"};
	this.rtwnameHashMap["<S5>/range y // range x"] = {sid: "untitled:6:848"};
	this.sidHashMap["untitled:6:848"] = {rtwname: "<S5>/range y // range x"};
	this.rtwnameHashMap["<S5>/y"] = {sid: "untitled:6:849"};
	this.sidHashMap["untitled:6:849"] = {rtwname: "<S5>/y"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();
