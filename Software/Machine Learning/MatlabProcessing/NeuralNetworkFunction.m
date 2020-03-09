function [Y,Xf,Af] = myNeuralNetworkFunction(X,~,~)
%MYNEURALNETWORKFUNCTION neural network simulation function.
%
% Auto-generated by MATLAB, 29-Feb-2020 13:26:51.
%
% [Y] = myNeuralNetworkFunction(X,~,~) takes these arguments:
%
%   X = 1xTS cell, 1 inputs over TS timesteps
%   Each X{1,ts} = Qx10 matrix, input #1 at timestep ts.
%
% and returns:
%   Y = 1xTS cell of 1 outputs over TS timesteps.
%   Each Y{1,ts} = Qx1 matrix, output #1 at timestep ts.
%
% where Q is number of samples (or series) and TS is the number of timesteps.

%#ok<*RPMT0>

% ===== NEURAL NETWORK CONSTANTS =====

% Input 1
x1_step1.xoffset = [0.18;0.47;0.4;0.53;0.09;0.31;0.63;0.67;0.77;0.8];
x1_step1.gain = [50;25;20;4.16666666666667;8;3.27868852459016;10;4.76190476190476;2.7027027027027;2.73972602739726];
x1_step1.ymin = -1;

% Layer 1
b1 = [2.2221347014467447423;-2.2408975473273842205;-2.1294381582813617371;2.1042176308208562219;2.0463454007014756364;-2.0626150073755327163;-1.9659146168663867993;1.9402074494000352001;1.835076637784544662;-1.8122324518136008198;-1.8335646507187974841;-1.7250384772202063122;1.6447892623155107028;-1.7016167199162861579;1.5822903719661902677;1.4982702118973527661;-1.5050465848752947462;-1.4557780451583182124;1.4111445512480262909;-1.3609672053675581083;1.3918261849970947619;-1.2913584097822172758;-1.2014181064755400374;1.1198364252547923225;-1.1636126374927775462;-1.1109877355446411418;1.0435306197559075514;1.087922379627555225;0.94319981880490666448;0.91050568908576345883;0.86830503839065364957;-0.76976167283684371334;-0.7788647564558245362;-0.75907753947437928144;-0.74299680634678211266;0.6223463954327640435;0.62234236604533677006;0.63087686479841664777;0.42474348566975611563;0.47069843887342294186;0.45717937690421733832;0.38730984877739271788;-0.33354021696973729094;0.28573379002359239331;0.17933108538939160348;-0.25158601118860063339;-0.18590115382140490197;0.10874525455467547175;-0.080823002100498364531;0.025193996797285334727;-0.062143925424166024385;0.067000214657197618151;-0.10306629835205832757;0.18454543598832467977;0.25485543871508414826;0.23516637380514632261;-0.24252754629803233155;0.33987647575276813683;-0.3860735100818287191;-0.4334329392209425591;0.4599338321218108816;-0.51599048128435254235;-0.55336657528964305897;0.60028738737089226696;-0.68959422501636091773;0.69086550803716917368;-0.7346975584008074156;-0.77596175864820693402;-0.7810831649762608464;-0.8786038281194711308;0.99488304984526620967;1.0116687303535729647;-1.015060595343598715;1.0895919640133253647;-1.0043423514437430644;1.1374488584241297939;-1.2664486264670413718;-1.21202101782912397;1.2845052865330750524;-1.2717239860053843881;-1.3871898012800396582;1.4329955635657736224;-1.4332278534848317264;1.5395655357287356679;-1.5430467961065876814;-1.5904928516398904037;1.6177327828826593148;1.6745245858544706152;1.7307066784802289661;-1.8050532223870843218;1.7912910963007269149;1.9188513215402653866;1.8017110284476400839;-1.9597860279189591726;1.9919323653897578197;1.9490193103329023216;-2.0893322279537520636;2.1320043699533748338;-2.1954781131365792568;-2.2270655874467668589];
IW1_1 = [-1.169257939254982448 0.18505019666984973137 0.33130172519431266842 0.32881320801904556639 0.14641538687254893047 1.0114744559388184619 0.11183161928503396187 0.87485543328870296609 0.45576743835960864537 -1.1226139456974113529;0.83392323462927897548 0.68293593227724647132 -0.55647339698299402855 0.94503752520176997898 0.91782170199990431581 -1.0257478000038768862 -0.016781710677681124788 -0.60169523831850224571 -0.17209753868469318538 -0.11930698530380844102;0.46872956378028957092 -1.0862194240848144222 0.12291718112027945342 0.63221844460457632398 -0.3451242505978165398 0.72357342985374917266 0.31309332654072941082 0.75506229452199546959 -1.0746530506492504298 0.80125757244546624847;-0.94137020350575162375 -0.67844436681507414022 0.074340915301314883235 0.69775822048744595705 0.6359252969969485525 -0.51675477280721482387 1.0552375921475820597 -0.83858836435769534834 -0.63359509438772243506 0.38702279580529230785;-0.88146291349560357276 1.1495761854256629775 0.31059046952116098339 0.76564406975979271142 0.49961352940320385985 -0.045707931506979743164 0.31646017582746988062 1.1717663463457927975 0.22624408880711935343 0.5947035601258866544;0.52318162076620167156 -1.0117093721416876573 0.32155393052750597116 -0.32030913637906954783 -1.0151151270993996611 -0.87920147822481031774 0.16386821880271662533 0.91670087535600686124 -0.27119635518123902385 0.68023862888004382743;1.0059482437991529302 0.90084830160393536413 -0.42632601201846959116 -1.127073889005067997 -0.70879686895853510897 -0.91675807598867642412 -0.28816247472456629763 0.3125061051146808544 -0.034630500645175400776 0.26353320865145107854;-0.07850294945400232427 0.12823855869200542767 -0.85415295532298940451 -0.59684822758077760163 -0.9941829291953945269 0.28959146072774560876 -1.2863653226783378081 0.37782534843051862605 -0.47961079866173528252 0.76211544674334608107;-0.31769695548072407476 -0.087804993083520632702 0.66897787267614883255 -0.99711902305090183152 0.30972992482505412593 -0.3037936880024817432 0.076795096102638737978 0.92251055966657502516 1.1193628076892312428 1.0939415628561701688;0.60307681221186804077 -0.4714855486039645216 -0.96114513973139970027 0.42925168766712124002 0.17267475462057627067 -1.2996533693473046878 0.017959153655190497612 1.0975861987978132728 -0.21454172703200802275 0.51546533633664937124;0.74617778825309233337 0.78649350362266134962 0.81525376752220057863 0.3666408813513604148 -0.74358687648990029473 0.93668709752111345423 0.46297294113816822581 0.82169664398219222079 -0.086696884885603203719 -0.67416522954633761877;0.020355541260424832306 -0.418956794253029563 -0.98184242205990113206 0.9652901236320309275 -0.39717653801978275441 0.61616231928324693978 0.51639913725796438015 0.83414612904276186356 1.0743381769014477278 -0.45071844256032439491;-0.99740479163451389866 0.69746109351953622379 0.061860351200913196723 0.37807924678172832866 -0.9920858123955207386 -0.089861928546854277777 0.53754593923962679103 -1.0067484249215907788 0.28852965862941026831 -0.99176209846804341819;0.72471083690804360966 -0.2584699616569572922 1.1479139883563118651 0.95984138165557619793 0.76384146536049379872 -0.18254035339934288062 0.4983952395391274548 -0.80843476082562870655 0.44982714845354682121 0.38652831179752433766;-0.45479931232615722347 -0.033809037258066512721 -0.62773164565100914025 0.024517749809666925659 1.3340934286180128332 -0.73781458141013722685 -0.8601332554396043939 -0.27048684749126972182 0.74514873233577605394 -0.79414970242271532008;-0.75010497141978127456 0.42333358785591401752 -0.080302712165726375382 1.1050588314184597305 1.2240122877647809929 0.20994385126742648451 0.18188794168511684957 0.53288996296803048391 -1.11598566670885746 0.32660659142268683164;0.31156370523153065211 0.19221499201076339136 1.0725150440195156953 -0.018012359499819399766 0.8148862727319718946 0.17145243796265069447 -0.87825809267654919577 0.23202528620674350845 0.91525326022826558603 -1.1301005672295536542;0.88857591629620680251 -0.78891807210446929233 -0.52846647798391022111 -0.61215716201722025769 -0.78932967093611949849 0.20430345913129499547 -0.32929363277934153853 -0.57660841618305291867 -0.83503836524453933787 1.0303419402363607205;-0.76142846015460408093 -1.1274489464009849193 -0.15747174022586379882 -0.81073273977184534544 -0.82013743253555815294 -0.63510097098931828086 -0.68030682654507024232 -0.3515314909204394489 -0.46506852288480321489 -0.71219767697236668891;0.59972647731928840908 1.1020894994354490937 -0.47971546115838054059 0.088107786320178294037 -0.79607611898710584075 1.0458307858570627946 0.4275809511688089537 -0.75331697150187604262 0.39314126887269862376 0.69422288155559730427;-1.1170795899192176304 0.57880688702674121249 0.85084237843062704432 0.44528424934676091862 0.46348078245036061773 -0.26342636343495734463 0.40926356929918905614 -0.87810820435088443592 -0.90635829633828357554 0.44013968303420403227;0.049589419969161226132 -0.015759889553493038744 0.8916894045711363237 -0.69961971513581588944 0.25822773084308497937 -0.70461735857490459534 -0.21082618770491656779 -1.0754769868824021195 0.96935372149248089091 0.94878634937701333829;0.90060262785783984363 -0.73664470541218196598 0.75453561509139654984 -1.2095162132874717198 -0.056197877770643021866 -0.72818764044854766837 0.55694353326351953015 -0.041429933268487949272 -0.31278530232275397749 -0.80244952368067801185;-0.44703833595976377735 -0.55995295564292835166 -0.9757814209835438124 0.40096666606441871972 0.23017972771063688331 0.94938424859885417462 0.55583112151010105606 -1.106448405714729244 -0.85802196021506738077 0.51531307536596282493;0.85665512145609523653 0.087441609608088083361 0.73464425394266064107 0.51222496981101273139 0.54356954557391345961 0.9758208591449586411 0.086458071014771542551 -0.83859282779091903759 -0.88532432218608037022 -0.72859972525448202241;0.64645744383248826548 0.95223447390574278426 0.35903672769154199029 -0.32395322569325690765 1.18169485217100112 -0.38255801716354920217 0.37350993246853142482 -0.88716751990879572087 -0.40078084151220894071 -0.88199067582063672699;-0.11498543526748955523 0.12059098521713138008 0.84259924647245587614 -0.81351835860186505478 -0.80064177112879320042 0.39955384014477224319 -0.9103093275559100972 0.89103601985450964218 -0.94418943371048358326 -0.45690567832561784778;-0.25779378076059067393 -1.1575394737671311773 -0.58564096126166831358 0.38080195699519503449 0.15876544705255590806 0.34324473111809838954 -0.64092105858880410452 0.3575176772267911196 1.0750068024983920889 1.0775402195781773607;-0.4554358455249256088 -0.92977390469233966996 0.94231306161286321199 -0.074807806976691551548 0.46338511365041556989 0.82734273250094736429 0.53440365269952538885 -0.79261558691094402551 -0.66741686757293339216 0.89640450514761460532;-0.66606755410682605412 -0.46129389385788183153 -0.11275045068529353232 -0.74472817407605362838 -0.74477002926944146921 -1.1579207713222519072 -0.11171654296507048387 -0.77273897573273686579 0.96983624349141894783 0.52536849550854902713;-0.5443415179520810776 0.53420474349346924736 0.81866797936842827799 1.0296238156874928382 0.92272479829004050433 -0.12544457705953837579 0.042983779598502469543 0.88323245883980150417 -0.47718679407896363864 -0.88716528496500357548;0.9875649405769036937 -1.0221175704324731992 -0.83978505984251683447 -0.25321803237681850263 -0.32590734253122388697 -0.53835691459028200967 0.34837763632443113915 1.0209561366723147735 0.7205467407191127327 -0.46655154825970301946;0.51083488837243273828 -0.20418519288084277519 0.94856255174789150253 -0.97048878707024655021 -0.6172519680853622015 0.4946327745869629755 -0.7854719640184253393 0.59070896910767256571 0.89463439267689559564 0.62488689636215888346;0.11169611607158710931 -0.87452900680626710628 1.1408572260673530696 -1.0386236857095714203 0.90432084712497606827 0.34188295243291844105 -0.11883568077699810384 0.72464058297099476214 -0.037567941287589043386 -0.40893015931022125287;0.5551158461735302696 -0.67631360054419142891 -0.73731536304541878124 0.35362284699014556733 -0.49312912822794652268 0.91668138594215164972 -0.95349250144176100896 1.1109231910480621419 -0.27178962826299130073 0.34681793266691873789;-1.089811074000519131 0.44162889113957815024 0.1449953212020674842 -0.81456163470978548702 0.54739470689220259825 0.61708913034279411214 0.1848025733035957574 -0.24620538262660510154 1.0584779810631623764 0.98576796585317616461;-0.27023527422334558956 -0.10126495925906296713 0.69101148449650706684 0.8282211419916873929 1.0318584487113249271 -0.093457493264091875962 -0.91633652110168273275 1.0508412335223749068 -0.4732573609021522576 -0.56626966651162313759;-0.66804615089048569043 -0.34897377017004210797 -0.32518230334494341305 -1.0468960772595776731 0.68098434212768998997 -0.73044239101396579716 0.60256724794540938994 -0.9637525429200406446 0.80675684664713209759 0.40404634412263024101;-0.41476135833297583799 -0.63703582518260815082 0.69012770924193866939 -0.054058164755271337354 -0.82160011946295430363 0.88259620747665812335 -0.78536140909643936681 -0.78368281649714099935 0.85190173225793430767 -0.79753698141466777827;-0.68276476196195312607 0.37483319959728861326 0.40213338642241613918 -1.0054434111295715848 0.76545359382379640767 -0.89260945278492975774 0.95930165918261822711 0.36450287099580125361 0.44103677546253217123 0.87510949393227488446;-0.92261814268861142008 0.40207047708489351834 0.31298833484894383883 -1.0601929262377078889 0.57356072252582601667 0.8765314461067226226 0.83111237400930071395 -0.47089619837594676177 0.86536542529450144468 -0.086085865717831971944;-0.61531879072469430891 0.59752803392103925884 0.55574475581425242243 -1.2887094290531218022 -0.4846483779212291676 0.85464707642706760904 -0.12380109264588927409 0.91764632528053358129 -0.076990008069556720161 0.63179745938102960245;0.041875624553037553432 -0.58564407437349164098 0.82964614806949421588 0.0023304069967376283418 -0.50480299791907157214 0.79138554631992918953 -0.14595792453729117266 1.274102226522955128 0.79474486327728799395 0.85293402887443703353;-0.28528159541155095891 -0.52686871658167166999 -0.92634763860755486853 0.91793542538066663639 0.8228620409144017378 -0.31883306401019495535 0.32258341763229853028 -0.94266056900542760655 0.93505634890630440204 -0.57560739295362717272;-0.14955802367572809675 -0.56969869674942852367 -0.75307435104035858053 -1.0262632422522504072 -0.71335212233847944407 1.1702178920457413369 0.3073703751316296251 0.21795657239594265486 -0.16391245537011611688 -1.0156467440950482928;0.0827406964100638187 1.0520677625560932444 0.11161218751213934641 0.18287033064729338316 1.1964832226373365298 -0.91773074805175247626 -0.42921284805177339905 -0.94373565427467986932 0.56952994012023694381 -0.41790465147784638944;0.45119062126683634473 0.3898879912829142369 -0.38699380207317152225 -0.79394680748545976012 -1.0944919509583035389 -0.7817660274402011833 -0.92443632988730883859 0.01531561570934345147 1.0347115724595705721 -0.2667384393923381003;-0.74810862004378775314 0.50958331077686713773 -0.72114243439453762363 0.067198713284150141112 0.56226313289483542679 -1.280997590737000591 0.36030707981417764429 -0.35291915139488416742 0.28717195674435358477 1.1120031287212255311;0.5676481887930269199 -0.38687962939805653484 -0.37045983129683673907 0.80308230270952318808 -1.1530103736462700148 -0.58568277915265187783 0.71513342046002525976 -1.2038017082014003112 -0.19074489163130620151 0.27400344266004689198;-0.79056119808299885054 0.79701553766328947503 0.69105053304462338293 -0.35222998807371497243 0.99585689116895437234 -0.92381158490383674664 0.0074558905764240982969 1.0006474339685365038 -0.45919199966592105788 -0.12229814424578740184;-0.87102010328132783989 0.27647686150413647299 -0.28565143023487782337 0.60092975261183212421 -0.85262429379025550524 0.30073368831112101685 1.0306567261284198533 -0.69487247496092385823 0.77713079303191290315 -0.79298870784654240662;-0.021385131669420871098 -0.23493583451286875752 0.98713519465008636722 0.026245666970669021684 -1.3185634236075909342 0.87250552759549038218 -0.0073576113907925554461 0.20860702073143777557 1.0142622083742485195 0.57272054877269440443;-0.18336946076408272566 0.44065513968275721313 0.34630996065168961895 -0.81279217032795869624 -0.66601434005567505814 0.4781793573554667387 1.0766291486183108272 -0.45958664223467815546 -0.81269631203837378042 1.1108616852302695133;0.62272028887036412481 -0.95617468461217336451 0.083013820404046367862 0.67391692956785043123 1.1608973890727252165 -0.60570945726541924881 0.37860324894030944476 -0.65945488911849581282 0.97877118342141433693 0.1225136928632791361;0.91361165756320095177 0.016592435405866176601 0.58822387941705533976 0.44424621368672090327 -0.69689977282035109329 -0.58319639449860261049 0.91730564388044177893 -1.0209679003492937444 -0.11940949918115656425 -0.8997966110214447033;0.82445493878898667983 -0.95914546406982614801 0.71741786283569053406 0.39380163570245335647 -0.94766691772424715978 0.76780700677425961498 -0.6311027169415034388 -0.70733460705152351178 0.5218603818076866796 0.24966429262775299835;-0.65239264287509335372 0.40137485986927945447 1.0532297493478610662 -0.98843646119071093548 0.63880015667098510868 0.72282357380583894813 0.79772790894376199855 -0.6843705202484320349 0.56309153400504874387 -0.18201464651387472271;0.46975025971608258546 -0.83042351977333517254 0.055373771454859430086 -1.1205802077628934654 1.3218519369722563361 -0.29642637969567786627 0.70351477470950163351 -0.37165402159749960642 -0.1716020351212530215 0.50425588736796511657;-0.22040407276964907313 -1.0731498829054810784 -0.87851627404589993642 0.37185227682702348684 0.96418120633811221776 0.92063330898134665414 -0.25643131905970806272 -0.62461172228173589271 -0.62369313620502730977 -0.49704903831296465277;-0.4425311658816681315 -0.96739922770940955932 -0.063909729905402390404 -1.0358215123218041942 -0.82861666928777300001 -0.58602260320367205448 -0.90754928958831992958 0.31893881015511327259 0.89028935906385398003 0.095956027288540135523;0.087470635172801153301 0.89405884528867241023 1.1356781763196082125 -0.077930642720450929439 1.0284298097931856564 -1.0269172171308498243 0.50533836847688218263 -0.28515942745702377303 -0.031609425957309665589 -0.64723968873369919219;-1.0090133772278020441 -0.42123245225347877296 -0.65453185974388472523 0.15164149040499241838 -0.83750209066956871062 0.71695343419830703802 -0.5605507020700857268 0.43416142027064458242 -0.95599982525097060293 -0.79480263485808022583;-1.1677282436436788871 0.26123398048295048968 -0.48571388526523356921 -0.83234704772477752233 -0.097657970479843286826 -0.76688180708893949333 -0.9519677432966597852 0.62122316590886639265 0.14580536958166462336 -0.79914399769380006777;1.2484171852873771069 1.3200555187512235111 -0.57630193173524113526 0.17946630472924576805 0.97314029356821474259 0.45727358114217553364 -0.058191763472150277725 -0.17413580136174316992 0.29837544241025776293 -0.12127313769978388669;-1.1869319457720794997 0.23828805685934312253 -0.39603419213336005233 -0.40727215700153529543 0.68406368121395999538 -0.6894532125323167282 0.025184992631792146173 -1.0274444792279167071 -0.38931268153083808947 -0.96705089226553631043;0.83124291238554892658 -0.29371932768421915583 0.99406671300969406957 0.13647313864437854436 -0.0052744155942936214385 0.86698204522341126843 -0.60136988517012135436 0.52114263574885566488 0.85036262676006824091 1.0146910592180231614;-0.50306942788432229552 -0.83005797300818995321 0.89581690217503706641 0.89905109522422432811 -0.5313325127369874501 0.43255860865857620468 0.85567109343406222433 -0.83815609192468409905 -0.42705808900394526262 0.53344757402611320263;-1.105610284518734332 0.86119402931620281372 1.0794129256284763496 0.86523322516545864147 -0.20183427755419752758 0.42993746324494347411 -0.71401841715258484999 0.05883714221871642891 0.36182300282960411231 0.39149892049996337651;0.0020243938546995947185 1.1389216344568819927 0.82104588129454225687 -0.37552178249605955296 -0.63329598041967449795 -0.86643754759170610313 0.63592565157185299007 -0.03537096704164289368 -0.54936155350828241861 1.0292248770407539382;-0.90130412346336596929 0.49401526988157878906 0.092872214996214480509 -0.42170793188003086183 -0.39463207070702888135 0.59651389117312680899 -1.172105543110778747 0.63774735799175996664 -0.62215677874753294585 -1.061652089213679151;0.54498494583531886803 0.40902957328665529024 0.336677677062150571 0.60320491946788701298 -0.51720258022962906086 1.2665015503749008641 1.3601792097535541082 -0.39402797384584897777 0.28559258190232378327 -0.13414808553880827602;0.95928268088511337019 -1.1816361417113179222 -0.77581094324410493357 -0.63235049230942608212 0.60495084961551515157 -0.29317888496216165661 -0.99878735584038047524 0.017956963250511989022 -0.19404196791634673036 0.31564228499256585803;-0.51546455857216821883 -0.29253352078790861857 0.88120558709848528789 -1.0533756666327733775 -0.074675561902366530131 -0.29378039741300726595 -0.90694711976356578997 -0.49890173560965722643 0.86099376725321907777 -0.87528764124811908598;0.35665347449207046582 1.1446969236624462418 -0.71742324651442090921 -0.092553853243939818163 -1.0795583958194219232 0.57829697555408487997 -0.53876925160929411973 0.8229137515146738302 -0.66009862075295233641 -0.0051977103772848712304;-0.70093535841650389528 0.23002718147186873576 -0.41251047603198987002 0.12302161362964494917 -1.0221679419429112734 -0.45292305050324693783 0.80155588599426685903 -1.0451116822151109709 1.0645579604713719668 0.44410108565141903636;0.50695888344187411967 -0.32191946174011493165 0.75100391934281995887 -0.17411064266845327486 -0.42399289696436032182 1.0757863153946229939 -0.29166156946588184251 -1.15832217903945911 -0.90703189998825684004 0.62143282343641814691;-0.33050315061078344714 -0.54720751331528860728 -0.46142208793310984793 0.87863652544503134667 0.13113634639423210615 -1.0852450102329622705 0.51443546197546263787 0.047232451897289182141 0.83033475813007717736 -1.0882247550997379282;-0.7119738834686506479 0.29691123688214066112 0.31589524026263526846 0.61091312401923736353 0.746936307104779873 0.27399594716016217877 0.6824975657797015538 0.6954918225747876992 -1.07850666164836273 -1.0728219296242160752;1.0365897477748267086 -0.61495544951975222858 0.050938579713232741419 -0.87565448098681597511 -1.2207611775310054369 0.56999051501841069278 0.29320464757834036051 0.27995785390228367095 0.63906848393527870833 -0.55544030792796683649;-0.74702582206454137825 0.70370992154633749127 -0.10286187021069190251 0.73730391143556450739 -0.37733920472664450596 -0.49761025338817588271 -0.7849142787196985438 -0.92520844232385734962 0.82278805831852996899 -0.96524419533032734808;-0.14141849471821807405 0.37641342149905648862 -0.92130609655167805538 0.7597062679164304777 1.4622510666863761664 0.10648799578590055492 1.0318320736338848498 0.081936178968097475583 -0.01370250407312734349 0.29016172447733956652;0.72217046807550278054 0.75096794589061066638 0.35822501459983407956 -0.8716620077656485055 -0.63772783342242811422 1.2723846315578237753 -0.15269580790726058894 0.22975655586424889587 0.48350612878758819635 -0.75419858161398367624;-0.75434830572128286352 -0.34026502746678094491 -1.1331093759491617234 0.25576360215556659394 1.1581112302122040791 -0.61076103791265667908 -0.76016484270150364022 0.46072766275208293374 -0.43543962997971674689 0.50749368250774629097;1.0324323450466192931 0.51317182239227610019 -1.0406644274601575262 0.68997000581334344549 0.0016990432541447453036 -0.71685242087277145639 1.1041698150584211557 0.3289416978742988884 0.011494301144525372743 -0.31778981793920829668;-0.86641883292476573608 -0.44771511002101804788 -0.82770598205766898747 0.41458556275241720268 -1.096683448172400599 -1.0747692484629010057 -0.46139408012157223649 -0.47353262018793862431 0.41130543916095274604 -0.41673127415911126459;-1.2016150531437372884 -0.51553132587399730369 0.83125831612043477037 -0.018337267039399508806 0.22078470133597352665 -0.048370285116633764122 1.3117105408123590493 0.666202717832302449 0.28073127427577587722 0.4774211334663211459;0.31437632218526928574 0.26026687852344554397 0.075444036610041745328 0.33043343363810723234 -1.2829313189423956487 0.40005955564824846604 -0.6350154006105804827 -0.030886407930024520341 0.94863771872808855257 1.3024276762885043102;0.64351435646273769109 0.77773453223747268659 -1.0556444273177714166 -0.53859639497080524784 -0.29024259480532965672 -0.58612887282814851719 -0.98353469052376241155 -0.56355005312805428463 -0.58341833548155541678 0.67216918656973556612;0.45193286835685259062 -0.99224198951919351241 -0.53071669178023739288 0.8676079291529188442 0.32163783629284187215 0.75644344513165751032 -0.85198137767396975306 0.9731443930633257855 -0.10134882438816002204 0.56136549094277654604;-0.75953138919187035416 0.44846313154095285292 -0.72869558528888245252 0.67460219865746440249 -0.8427166253081740388 -0.51521075365525459411 -0.0039612605469077580983 -1.0677816002109823401 -0.15691822086052978347 0.9478030776953593195;0.37409257352499175608 0.11666705307847947959 0.20322367166410254535 -1.1903311387086175088 0.33086888492274529883 1.2287280887327984846 0.5643502725221063443 -0.6160503784417687978 -0.94806176655465623782 0.36851564091295774261;1.1114768810028805568 -0.55174045894210077545 0.66871972589038120027 0.03422945817969810095 -0.26296090026780594151 -0.35403972017065343802 1.096129287792822149 -0.21991555574442753218 -0.93918580253178696182 0.68594620727858501841;0.69766034081491268282 0.6524429241772498056 0.47050528961234799885 -0.96521176419428134086 1.0528834408216174445 0.59839525246823688232 1.153743798065383297 -0.27105157781890193425 -0.63915425778111489841 0.2414110294097146503;-0.14272731011526504363 -0.70033247724754088548 0.11970886186712695332 -0.63920537132220378584 -0.77860090440147100566 1.0692448940786685174 1.0750602705792031699 0.63696617767934460286 -0.2944132198556177471 -0.7622854523006769023;0.21484373444108720297 1.0125906821690966453 -0.71804873433346960709 0.84858641984664928692 -0.50194304795948507802 -0.8806353477917258088 0.2681295838610010529 -0.66396966062644569018 0.86720651384319458188 -0.57186671649767606418;0.52229250199931465115 0.3927761666828100684 0.85964273218025932799 0.41960826193011491192 -0.77280859610662966386 0.25911228022575311103 0.39935895363451912043 0.75709000444392027251 -1.2189672087293665914 1.0158224776422282165;-0.54670996378647340741 0.83320274147941120191 0.16218359671804033484 0.1779003258685963873 -0.70405641508776029003 0.12473287374551388085 -0.95433759006086760213 -0.44144355805772489409 0.32790190501092603137 1.4623836938986916056;0.7768091054781071092 0.24037454003992178575 -0.74717379859174026802 0.92942305103320499438 0.42195102614688057008 -1.1745859767395023798 0.55400591160734569129 -0.79328363928546008488 -0.31216092966650837992 -0.49056067493758309661;-0.6252231919406973093 -0.53582886852824263002 0.51605027999234331926 -0.13988392073220454193 0.48460560810359964989 -0.95262493484476074013 -1.040809042651008598 -0.25558290265488481374 0.39143759656052035112 -1.1819605806553203919;-0.69497852693721284822 1.0650507354401745896 -1.0547178898484155241 -0.46982575291521561089 0.0022644936199036178222 0.15784890664156916995 -1.0426718083815622595 -0.35415525755425908416 0.26920379807823185958 -0.79121237666072963268];

% Layer 2
b2 = -0.03543852849549366385;
LW2_1 = [-0.013846550234944611513 0.15350698049259881017 -0.068930239289319975016 -0.41189763493813025264 -0.33360399751188674067 -0.21532718789855798125 0.24585190873378651166 -0.013429637626118189758 -0.33821888007343137161 0.08787582203691093885 0.23989397690588740164 -0.16682741861255404037 0.33093695407917611551 0.07239997763253455676 0.41827047617148160885 -0.56866297775371954515 -0.23632627654247864712 0.30422262356532203675 0.13703783021710708168 -0.17208398979127270678 0.18623621842035847918 -0.014217541391244455443 0.056177773664202845794 0.42908104059603208169 -0.028860482333739004984 -0.95931372561963834666 0.23283904069785987812 0.80271848932735667681 -0.42748198447668828148 0.29521466949004554481 -0.51871303090478293463 0.56706025149497307769 -0.085034157523098077847 -0.010248407512205433625 -0.052365567971219037502 0.085215326238374300427 -0.0046134692158203757101 -0.23972434686085994371 0.63232983797057251696 -0.78518103145120876629 -0.46123775631473667991 -0.16573376917986290535 -0.087461657526922906292 0.41473752604814995149 0.59816327945242797615 -0.6396472663987857743 0.36450812181750924523 0.010730854775667764134 0.46964547682789992145 -0.3317798488273775992 0.003524000015058356694 0.49429714752955022927 -0.19895037648622815318 -0.48954836418709440915 0.16087937848935859875 0.50072274068193611818 -0.69485544054665426827 -0.15920042812157270129 0.36096685699448649576 0.85419689234796569721 -0.53066290796135551222 0.15460204736906849043 0.19623264888912622661 -0.62838991007426614477 0.31432385050344641142 -0.2055107523463575725 0.32790879816969831229 -0.39722353408662020025 -0.38389234340776084986 0.55412961628237944467 -0.79065228932663189632 -0.40394324223735866841 0.18234751051236869346 -0.10683091538213085325 0.62697123001802324005 -0.38276753086341924748 -0.19384991142450497259 -0.20390927645681602987 -0.058503347241591639738 0.40647880424922311349 0.12038048604759900295 -0.021467145582361932959 0.24335406023939956666 0.07142126090398900895 0.57434744551363281495 -0.037219149304050597182 0.50475988053901788 0.2079105807739402012 0.066651884911308981185 0.043322410363052378524 -0.43088148921380053924 0.28310287959599594876 -0.79413160673367422238 -0.2958948424434654223 0.1037692147468681908 -0.59184173657372729505 -0.31257501687337096996 0.31623468656130931942 0.078146696915156715901 0.15884607715940113337];

% ===== SIMULATION ========

% Format Input Arguments
isCellX = iscell(X);
if ~isCellX
    X = {X};
end

% Dimensions
TS = size(X,2); % timesteps
if ~isempty(X)
    Q = size(X{1},1); % samples/series
else
    Q = 0;
end

% Allocate Outputs
Y = cell(1,TS);

% Time loop
for ts=1:TS
    
    % Input 1
    X{1,ts} = X{1,ts}';
    Xp1 = mapminmax_apply(X{1,ts},x1_step1);
    
    % Layer 1
    a1 = tansig_apply(repmat(b1,1,Q) + IW1_1*Xp1);
    
    % Layer 2
    a2 = logsig_apply(repmat(b2,1,Q) + LW2_1*a1);
    
    % Output 1
    Y{1,ts} = a2;
    Y{1,ts} = Y{1,ts}';
end

% Final Delay States
Xf = cell(1,0);
Af = cell(2,0);

% Format Output Arguments
if ~isCellX
    Y = cell2mat(Y);
end
end

% ===== MODULE FUNCTIONS ========

% Map Minimum and Maximum Input Processing Function
function y = mapminmax_apply(x,settings)
y = bsxfun(@minus,x,settings.xoffset);
y = bsxfun(@times,y,settings.gain);
y = bsxfun(@plus,y,settings.ymin);
end

% Sigmoid Positive Transfer Function
function a = logsig_apply(n,~)
a = 1 ./ (1 + exp(-n));
end

% Sigmoid Symmetric Transfer Function
function a = tansig_apply(n,~)
a = 2 ./ (1 + exp(-2*n)) - 1;
end