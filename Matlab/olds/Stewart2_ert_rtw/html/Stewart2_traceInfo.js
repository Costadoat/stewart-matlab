function RTW_Sid2UrlHash() {
	this.urlHashMap = new Array();
	/* <Root>/Add1 */
	this.urlHashMap["Stewart2:39"] = "Stewart2.c:55";
	/* <Root>/Display */
	this.urlHashMap["Stewart2:321"] = "msg=rtwMsg_CodeGenerationReducedBlock&block=Stewart2:321";
	/* <Root>/Display1 */
	this.urlHashMap["Stewart2:322"] = "msg=rtwMsg_CodeGenerationReducedBlock&block=Stewart2:322";
	/* <Root>/Display2 */
	this.urlHashMap["Stewart2:323"] = "msg=rtwMsg_CodeGenerationReducedBlock&block=Stewart2:323";
	/* <Root>/Display3 */
	this.urlHashMap["Stewart2:324"] = "msg=rtwMsg_CodeGenerationReducedBlock&block=Stewart2:324";
	/* <Root>/Display4 */
	this.urlHashMap["Stewart2:325"] = "msg=rtwMsg_CodeGenerationReducedBlock&block=Stewart2:325";
	/* <Root>/Gain6 */
	this.urlHashMap["Stewart2:399"] = "Stewart2.c:54&Stewart2.h:85,129&Stewart2_data.c:56";
	/* <Root>/Potentiomètre 1 */
	this.urlHashMap["Stewart2:1"] = "Stewart2.c:39,47,230&Stewart2.h:141&Stewart2_data.c:68";
	/* <Root>/theta_x */
	this.urlHashMap["Stewart2:63"] = "Stewart2.c:36&Stewart2.h:83,120&Stewart2_data.c:47";
	/* <S1>/Abs */
	this.urlHashMap["Stewart2:151"] = "Stewart2.c:107&Stewart2.h:87";
	/* <S1>/Add */
	this.urlHashMap["Stewart2:326"] = "Stewart2.c:86";
	/* <S1>/Constant */
	this.urlHashMap["Stewart2:328"] = "Stewart2.c:83&Stewart2.h:117&Stewart2_data.c:44";
	/* <S1>/Constant1 */
	this.urlHashMap["Stewart2:329"] = "Stewart2.c:84&Stewart2.h:138&Stewart2_data.c:65";
	/* <S1>/Data Type Conversion */
	this.urlHashMap["Stewart2:438"] = "Stewart2.c:118,129&Stewart2.h:89";
	/* <S1>/Display1 */
	this.urlHashMap["Stewart2:453"] = "msg=rtwMsg_CodeGenerationReducedBlock&block=Stewart2:453";
	/* <S1>/Display3 */
	this.urlHashMap["Stewart2:452"] = "msg=rtwMsg_CodeGenerationReducedBlock&block=Stewart2:452";
	/* <S1>/Divide */
	this.urlHashMap["Stewart2:327"] = "Stewart2.c:82&Stewart2.h:86";
	/* <S1>/Saturation */
	this.urlHashMap["Stewart2:147"] = "Stewart2.c:60,69&Stewart2.h:132,135&Stewart2_data.c:59,62";
	/* <S1>/Sign */
	this.urlHashMap["Stewart2:150"] = "Stewart2.c:71,85";
	/* <S2>/Data Type Conversion */
	this.urlHashMap["Stewart2:149:114"] = "Stewart2.c:91,102";
	/* <S2>/Digital Output */
	this.urlHashMap["Stewart2:149:214"] = "Stewart2.c:104,233&Stewart2.h:111&Stewart2_data.c:38";
	/* <S3>/Add */
	this.urlHashMap["Stewart2:36"] = "Stewart2.c:48";
	/* <S3>/Add1 */
	this.urlHashMap["Stewart2:38"] = "Stewart2.c:42&Stewart2.h:84";
	/* <S3>/Divide */
	this.urlHashMap["Stewart2:37"] = "Stewart2.c:46";
	/* <S3>/Gain1 */
	this.urlHashMap["Stewart2:28"] = "Stewart2.c:45&Stewart2.h:144&Stewart2_data.c:71";
	/* <S3>/Lmax */
	this.urlHashMap["Stewart2:33"] = "Stewart2.c:43&Stewart2.h:126&Stewart2_data.c:53";
	/* <S3>/Lmin */
	this.urlHashMap["Stewart2:34"] = "Stewart2.c:44&Stewart2.h:123&Stewart2_data.c:50";
	/* <S4>/Data Type Conversion */
	this.urlHashMap["Stewart2:20:114"] = "Stewart2.c:131,142";
	/* <S4>/PWM */
	this.urlHashMap["Stewart2:20:215"] = "Stewart2.c:141,236&Stewart2.h:114&Stewart2_data.c:41";
	/* <S5>/Add min y */
	this.urlHashMap["Stewart2:148:846"] = "Stewart2.c:110&Stewart2.h:88,107&Stewart2_data.c:34";
	/* <S5>/Subtract min x */
	this.urlHashMap["Stewart2:148:847"] = "Stewart2.c:111&Stewart2.h:99&Stewart2_data.c:26";
	/* <S5>/range y // range x */
	this.urlHashMap["Stewart2:148:848"] = "Stewart2.c:112&Stewart2.h:95,100,103,108&Stewart2_data.c:22,27,30,35";
	this.getUrlHash = function(sid) { return this.urlHashMap[sid];}
}
RTW_Sid2UrlHash.instance = new RTW_Sid2UrlHash();
function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "Stewart2"};
	this.sidHashMap["Stewart2"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<S1>"] = {sid: "Stewart2:157"};
	this.sidHashMap["Stewart2:157"] = {rtwname: "<S1>"};
	this.rtwnameHashMap["<S2>"] = {sid: "Stewart2:149"};
	this.sidHashMap["Stewart2:149"] = {rtwname: "<S2>"};
	this.rtwnameHashMap["<S3>"] = {sid: "Stewart2:52"};
	this.sidHashMap["Stewart2:52"] = {rtwname: "<S3>"};
	this.rtwnameHashMap["<S4>"] = {sid: "Stewart2:20"};
	this.sidHashMap["Stewart2:20"] = {rtwname: "<S4>"};
	this.rtwnameHashMap["<S5>"] = {sid: "Stewart2:148"};
	this.sidHashMap["Stewart2:148"] = {rtwname: "<S5>"};
	this.rtwnameHashMap["<Root>/Adaptation1"] = {sid: "Stewart2:157"};
	this.sidHashMap["Stewart2:157"] = {rtwname: "<Root>/Adaptation1"};
	this.rtwnameHashMap["<Root>/Add1"] = {sid: "Stewart2:39"};
	this.sidHashMap["Stewart2:39"] = {rtwname: "<Root>/Add1"};
	this.rtwnameHashMap["<Root>/Digital Output"] = {sid: "Stewart2:149"};
	this.sidHashMap["Stewart2:149"] = {rtwname: "<Root>/Digital Output"};
	this.rtwnameHashMap["<Root>/Display"] = {sid: "Stewart2:321"};
	this.sidHashMap["Stewart2:321"] = {rtwname: "<Root>/Display"};
	this.rtwnameHashMap["<Root>/Display1"] = {sid: "Stewart2:322"};
	this.sidHashMap["Stewart2:322"] = {rtwname: "<Root>/Display1"};
	this.rtwnameHashMap["<Root>/Display2"] = {sid: "Stewart2:323"};
	this.sidHashMap["Stewart2:323"] = {rtwname: "<Root>/Display2"};
	this.rtwnameHashMap["<Root>/Display3"] = {sid: "Stewart2:324"};
	this.sidHashMap["Stewart2:324"] = {rtwname: "<Root>/Display3"};
	this.rtwnameHashMap["<Root>/Display4"] = {sid: "Stewart2:325"};
	this.sidHashMap["Stewart2:325"] = {rtwname: "<Root>/Display4"};
	this.rtwnameHashMap["<Root>/Gain6"] = {sid: "Stewart2:399"};
	this.sidHashMap["Stewart2:399"] = {rtwname: "<Root>/Gain6"};
	this.rtwnameHashMap["<Root>/Kc1"] = {sid: "Stewart2:52"};
	this.sidHashMap["Stewart2:52"] = {rtwname: "<Root>/Kc1"};
	this.rtwnameHashMap["<Root>/Potentiomètre 1"] = {sid: "Stewart2:1"};
	this.sidHashMap["Stewart2:1"] = {rtwname: "<Root>/Potentiomètre 1"};
	this.rtwnameHashMap["<Root>/Vérin 1"] = {sid: "Stewart2:20"};
	this.sidHashMap["Stewart2:20"] = {rtwname: "<Root>/Vérin 1"};
	this.rtwnameHashMap["<Root>/theta_x"] = {sid: "Stewart2:63"};
	this.sidHashMap["Stewart2:63"] = {rtwname: "<Root>/theta_x"};
	this.rtwnameHashMap["<S1>/ecart"] = {sid: "Stewart2:158"};
	this.sidHashMap["Stewart2:158"] = {rtwname: "<S1>/ecart"};
	this.rtwnameHashMap["<S1>/Abs"] = {sid: "Stewart2:151"};
	this.sidHashMap["Stewart2:151"] = {rtwname: "<S1>/Abs"};
	this.rtwnameHashMap["<S1>/Add"] = {sid: "Stewart2:326"};
	this.sidHashMap["Stewart2:326"] = {rtwname: "<S1>/Add"};
	this.rtwnameHashMap["<S1>/Constant"] = {sid: "Stewart2:328"};
	this.sidHashMap["Stewart2:328"] = {rtwname: "<S1>/Constant"};
	this.rtwnameHashMap["<S1>/Constant1"] = {sid: "Stewart2:329"};
	this.sidHashMap["Stewart2:329"] = {rtwname: "<S1>/Constant1"};
	this.rtwnameHashMap["<S1>/Data Type Conversion"] = {sid: "Stewart2:438"};
	this.sidHashMap["Stewart2:438"] = {rtwname: "<S1>/Data Type Conversion"};
	this.rtwnameHashMap["<S1>/Display1"] = {sid: "Stewart2:453"};
	this.sidHashMap["Stewart2:453"] = {rtwname: "<S1>/Display1"};
	this.rtwnameHashMap["<S1>/Display3"] = {sid: "Stewart2:452"};
	this.sidHashMap["Stewart2:452"] = {rtwname: "<S1>/Display3"};
	this.rtwnameHashMap["<S1>/Divide"] = {sid: "Stewart2:327"};
	this.sidHashMap["Stewart2:327"] = {rtwname: "<S1>/Divide"};
	this.rtwnameHashMap["<S1>/Saturation"] = {sid: "Stewart2:147"};
	this.sidHashMap["Stewart2:147"] = {rtwname: "<S1>/Saturation"};
	this.rtwnameHashMap["<S1>/Sign"] = {sid: "Stewart2:150"};
	this.sidHashMap["Stewart2:150"] = {rtwname: "<S1>/Sign"};
	this.rtwnameHashMap["<S1>/mapminmax"] = {sid: "Stewart2:148"};
	this.sidHashMap["Stewart2:148"] = {rtwname: "<S1>/mapminmax"};
	this.rtwnameHashMap["<S1>/sens"] = {sid: "Stewart2:159"};
	this.sidHashMap["Stewart2:159"] = {rtwname: "<S1>/sens"};
	this.rtwnameHashMap["<S1>/pwm"] = {sid: "Stewart2:160"};
	this.sidHashMap["Stewart2:160"] = {rtwname: "<S1>/pwm"};
	this.rtwnameHashMap["<S2>/In1"] = {sid: "Stewart2:149:116"};
	this.sidHashMap["Stewart2:149:116"] = {rtwname: "<S2>/In1"};
	this.rtwnameHashMap["<S2>/Data Type Conversion"] = {sid: "Stewart2:149:114"};
	this.sidHashMap["Stewart2:149:114"] = {rtwname: "<S2>/Data Type Conversion"};
	this.rtwnameHashMap["<S2>/Digital Output"] = {sid: "Stewart2:149:214"};
	this.sidHashMap["Stewart2:149:214"] = {rtwname: "<S2>/Digital Output"};
	this.rtwnameHashMap["<S3>/pot"] = {sid: "Stewart2:53"};
	this.sidHashMap["Stewart2:53"] = {rtwname: "<S3>/pot"};
	this.rtwnameHashMap["<S3>/Add"] = {sid: "Stewart2:36"};
	this.sidHashMap["Stewart2:36"] = {rtwname: "<S3>/Add"};
	this.rtwnameHashMap["<S3>/Add1"] = {sid: "Stewart2:38"};
	this.sidHashMap["Stewart2:38"] = {rtwname: "<S3>/Add1"};
	this.rtwnameHashMap["<S3>/Divide"] = {sid: "Stewart2:37"};
	this.sidHashMap["Stewart2:37"] = {rtwname: "<S3>/Divide"};
	this.rtwnameHashMap["<S3>/Gain1"] = {sid: "Stewart2:28"};
	this.sidHashMap["Stewart2:28"] = {rtwname: "<S3>/Gain1"};
	this.rtwnameHashMap["<S3>/Lmax"] = {sid: "Stewart2:33"};
	this.sidHashMap["Stewart2:33"] = {rtwname: "<S3>/Lmax"};
	this.rtwnameHashMap["<S3>/Lmin"] = {sid: "Stewart2:34"};
	this.sidHashMap["Stewart2:34"] = {rtwname: "<S3>/Lmin"};
	this.rtwnameHashMap["<S3>/Lmes"] = {sid: "Stewart2:54"};
	this.sidHashMap["Stewart2:54"] = {rtwname: "<S3>/Lmes"};
	this.rtwnameHashMap["<S4>/In1"] = {sid: "Stewart2:20:116"};
	this.sidHashMap["Stewart2:20:116"] = {rtwname: "<S4>/In1"};
	this.rtwnameHashMap["<S4>/Data Type Conversion"] = {sid: "Stewart2:20:114"};
	this.sidHashMap["Stewart2:20:114"] = {rtwname: "<S4>/Data Type Conversion"};
	this.rtwnameHashMap["<S4>/PWM"] = {sid: "Stewart2:20:215"};
	this.sidHashMap["Stewart2:20:215"] = {rtwname: "<S4>/PWM"};
	this.rtwnameHashMap["<S5>/x"] = {sid: "Stewart2:148:845"};
	this.sidHashMap["Stewart2:148:845"] = {rtwname: "<S5>/x"};
	this.rtwnameHashMap["<S5>/Add min y"] = {sid: "Stewart2:148:846"};
	this.sidHashMap["Stewart2:148:846"] = {rtwname: "<S5>/Add min y"};
	this.rtwnameHashMap["<S5>/Subtract min x"] = {sid: "Stewart2:148:847"};
	this.sidHashMap["Stewart2:148:847"] = {rtwname: "<S5>/Subtract min x"};
	this.rtwnameHashMap["<S5>/range y // range x"] = {sid: "Stewart2:148:848"};
	this.sidHashMap["Stewart2:148:848"] = {rtwname: "<S5>/range y // range x"};
	this.rtwnameHashMap["<S5>/y"] = {sid: "Stewart2:148:849"};
	this.sidHashMap["Stewart2:148:849"] = {rtwname: "<S5>/y"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();
