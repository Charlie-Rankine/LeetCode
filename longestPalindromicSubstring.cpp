#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  string longestPalindromicSubstring(string s) {
    int n = s.length(), maxLength = 0, startPoint;

    for (int middle = 0; middle < n; ++middle) {
      for (int i = 0; middle - i >= 0 && middle + i < n; ++i) {
        if (s[middle - i] != s[middle + i])
          break;

        int currentLength = 2 * i + 1;
        if (currentLength > maxLength) {
          maxLength = currentLength;
          startPoint = middle - i;
        }
      }
    }

    for (int middle = 0; middle < n - 1; ++middle) {
      for (int i = 1; middle - i + 1 >= 0 && middle + i < n; ++i) {
        if (s[middle - i + 1] != s[middle + i])
          break;

        int currentLength = 2 * i;
        if (currentLength > maxLength) {
          maxLength = currentLength;
          startPoint = middle - i + 1;
        }
      }
    }

    return s.substr(startPoint, maxLength);
  }
};

int main() {
  Solution s;

  cout << s.longestPalindromicSubstring(
              "gkjhdfkggduolghdfspogjdiutyusdoytgbsdntrhdndtovamsntrimhbvyoieve"
              "wrrihcmiomshiougsdhiom9voypmhiogmh9mvtmdritha9msmct")
       << endl;
  cout << s.longestPalindromicSubstring(
              "gidsfbhghjasjgbamanaplanacanalpanamadfguihfdipgjdsfougnhpasdfkmv"
              "aderosgjgoidfjgohdfgoijnfogihasdfopghsoighoihgsfogg")
       << endl;
  cout
      << s.longestPalindromicSubstring(
             "sbtqqffhkntshmcczulypldgmmttgzgunbocyynapxtoqueehkicqrxrglunloswo"
             "llsaznlgalfhheijsolihdagwagcaohmepwjoodphlzerlrgkgmmvsrfvbovdzcmu"
             "sdxejwfqhnlvkpirbzbzlwsdytbmbdrjoyazaoopgzohpdfpgygialreyfpwhzspq"
             "skdjmsistwmtzjvtntkjxmwmhbuyzdeuheatsqysrbbsiwrzgyvpdxhjymlxilvmv"
             "otixdhwpecjlefjtdegbowccgkbwtmuhxyjrvnxijvugaloaooswukwvnmmxzbvor"
             "htmkygjkutubvfntvdprxjrrdjbzzzcupaamhtmpohgnunaserjcyihsopnnjxiox"
             "fibyjcdsozjlufrzxxeqwhafsteonudlzrlsvcoeooampqldywgquksxnnxduytos"
             "erdrqqpqbkucfrdhzainsjavkrolugmniamhbymkztmzddlgxafqcohcxzdzoxayj"
             "evucslvigwuvbdefadurrtigdlimxotlsywykvvwyahsmihlukunjdefzsaimtjuy"
             "rgxqxslzpwzuuttuiyvhrdjlxltnvtlxyrpqadzomwrmnspyftantuovapebetbtm"
             "ynvqexmegwckevankcsairgfdnbtezjulhsgerpkyuehwfbeaukelaxnbweulawwc"
             "vvqftjviwxxrtuwnwreumbvantoxdjjiraobrnpkoyktpggdtxyenazvubehqqscq"
             "nbncwtrneuczogcjbnszqgixbuufdjtteawxfyidhaupglkcjttfwaxaeahdpoyvi"
             "voumaekiprrldqblhupnpuxjmawtbgntvzguhnddsnbflwwwszdhlsbakugjjuign"
             "kwtsmqwnzixajwmtguzpqsxqptdjrpzeinbhlievavmxhlmreuwnkxyysddkfzeld"
             "hjutqlzulggrkvdogzqcjqsblkftfakbplgwaiscitmvvaxczzmugdpvlbbdjpstx"
             "ujivulfnehvklrdudxkbhhiyhnhshmazmtziohascrasdgghfosjconsqypfihdgo"
             "oqwxuuphgqffbjwielpiqikezjbjzsvsslcbvcwvodpnxxmlarfwgyhmgkdfxzlfe"
             "uzcjhbzjxrodqymvjohgnjlrmzrpraxgsotmbgbjiuvvtuqnaybqvagtunlzubpfi"
             "knmpfkwcgxuufzzmakolvchsmhuobzscfkhuahicirwnvqewmqimznkuzmbmsqzod"
             "bwhisrhhxrmlvrapuewfifakexotkxxxbpozofkuoseiavbywpjnnipdvgkgvhnbm"
             "xnmdbxgzikaazebefpprehqaaccuxfumjnlggfxxqatoclhlypnzbwwlkfjvcdsay"
             "xjlwgibahinplushzuhcmjqkjoxcbmumumrjgukgkvmbqwucqzxiduvdgpisdjdfk"
             "hbismabstfcxfkehcoiboerqpkazloeqcsjdxmethnrquggqhoztgjmcmtlmvouxp"
             "jqzwtpsnvtokuyukojpqfwkqbflzuypxisalfcickvajswsudugpyfiwtnojzuiny"
             "owdjxdkesrinynnvfkgoctnnbxzogsmjtrjxjjyookjchqmgvaxtbkjysbnuhwjvb"
             "clhcnfnogzzymbnpcaqkacwuskhpdlfaahfjimpvewlboezzbnulpurcypimlkjyw"
             "sosncerwrthnuothlybhwgkgeyrfhruwabbdkphjmbskakvgnzzsiimjptqqugxlf"
             "vlezdifjcijvlgbliichxuiijtbfnssjcogaiysmvvjawznidlkvdekzwyisnzcfe"
             "dwqovmtqjqqgzhergwhoqrinzhtgvezuipmsluypggxgcgtbiuxgcnxggsrjyhqyk"
             "hmvqbchjcghebmtzmsflgctazaietlsqxhbrvizbelmesflvnmveetbebtnwpuclh"
             "hzkyenlmvzehsdxkynktmumeobkonpmkvkxsscjvvpkiqptznaicznhwhmfwbehdp"
             "nipvdgqjvdeqjhlrutpthitaqbevulyphaytokqzjcbqrwqvsyicrdwyclxkkcmys"
             "xnspchxsetmkvhbkrejmcbamdhjrwldnzwxdxvxudmiwhvgspzvqbvqdbtafnttxn"
             "doibgojgwelmpauvvrekkcdbfqhygaetyheklojlpytcorqemuujxbttkfhvotbtl"
             "lftjnkbtkonsuujxsavlpynsoinzttsrhqjvgxgvwmuglygvuvbnpdztbbaiitnew"
             "kqjrdgjivkiakynrgbkkeiryceqnobugtgnigctjyeaxuzmvfdvogxbbohsikjwmz"
             "vcxccibaoonudsydtyuzioixzvjhkkhmpsgiwrxxussjvxczxjbclhprofgmlglco"
             "lfqnzfneakxldzzqeplqdcrhepzsbacabxqyvigmbhjuuhjclwomppdyokjmcktma"
             "hzeeutewxmntlpgiarumbvjhdvdmrhoakdqgnpjfhozwiporawlhemqwvppxxryjz"
             "rsgarvtzjebxqrsbvolivlsojhiatucpibusezykbumskifneythncbhdvuwfpmct"
             "zqbcfchnmreepvlxyzpqschmxakjoeuuhlgtoksdlabbleifqdvrznuhmhphrraje"
             "swbeopgpgoiovdnembbjqimaavdvghbkupqtdjwwdorybsyxnhmxsywnwhyvxnwry"
             "olhajyvdpozfssbwdzwgsqayuvbqllablyjrwlwnwomzbgupcmpojwupzgbifndqq"
             "saugpilyletovsbuyvlllmhuckzorquglklhijavpfinoivcfkccendkaymhfhcbd"
             "vzgcafdjlobcveddcernakbqxgqcokvgsedwlqzbblqnfxellcevozvhikzywwjrm"
             "tdfsiydjjqzbzbvcwevxrndhrypvsokaqtgvlkieuuqcvrwucunmpdarelwvdparx"
             "lgimfbrnhwtyzetoejqzsklnvbzrfrdadeskjfrsjmmwkpejxhetsrgqpalxeklcm"
             "oznxoorvmfzmsitksdbtyaidgrvkqeeiquneagclcipgsnimlgzybiqvjirnebotq"
             "uvvvxzmcvlpcwcoqmogfxuevcclzczbqguftyizzhovssbztijikhmrvpfsszgunx"
             "hftwczivofbgnjkupbuyiyhojacrzcwccbwhvydafqabmyfswxzvgubjbpsyeaasd"
             "cmdwefdkgqpzbcvegvnydeqwvqoqidywvcrvldoeybafigoogcagemvklehuxghmb"
             "bztnsvirzlekddigmloyqohurqjxzadobgfddqfdglqshwbgegxlbmsfctnxtkdpa"
             "hyqtmuxqjqiceaztftujczeskmaidqtvorsiqjmqiwswtjashshvzduackwjytzuw"
             "jbwdsqgblpckalpguqmspwcvscqhbbqmpjuexovkxlncdlnvwrbhkrmtkzgjizksy"
             "frodtrdjkrovdftkgwqlxiisdqkebnwojeaynpplnmqelazsysuofurwokllliwky"
             "tmyuzgdldkpjztnwhomlsaurqubegaxbzsnlmogkcqkusxiaeijixvibrxsygdfyg"
             "omdigantpmirqtcyubuppqgbcfnhvjxuxhvxfsmuufogspwqqotphsaymctujzwdr"
             "oobdnlcojhxgoqjmaseysnvzixdvrqxhjrbqnezluzrxseibdyjqoucumeqyosqyh"
             "elfdgytfttzkqlpqouepjazrlnozsuvvxdrxysjuiwycoyneeyvvphrynohylwfky"
             "cabuskafwatttwqavpunfqkyuoyjhxlvlxoqdpsraryqmukcdunmqyurcqbqbixwx"
             "dwbmmxwfnnxshhztwtqyjyulypjqatyglsfijogbfnxdwcntgqjrliztzqgirsvzk"
             "zwrexlwtppsusrpmtivurtojrzvojoxsnetbzvwvqonjuovbymicmmzlmyprneuns"
             "ucuudxrnhdbxmdtazxxzbyhodambtfigipqxwxuljuhgsgzohsjpwobckwfgcirzo"
             "nvukwnjpwbbgjhshkegmultpsppxeesvidaepiqjvtvojsuygplkqqooozbybybdt"
             "uwfzflusbremzdsewmakgaqaufuaaemypkszdyzbcujveuqxmpgsbaxeycjuilijh"
             "mqkmmyrdyndqkpihvzxsltlrfcayxtrgwdgienxnyffwputfsgnizsbcglplewsnq"
             "dxkzjtcmegzlpoqexrxeyttihubjzpudvxmxihnlyjtmqzqfwojtsuzelbnprekag"
             "jdlbencnpxegzcxbfzozzwchnnelrjiegneshiabpwwwkhbaegynotzywpldliovc"
             "hnfjrfqvvfokgufuqhsjcnywivmsctmqvmtzqvnckhhckvozrygwpqsgirjlpzuxo"
             "deuavfagadsnwgaxldvsgapwksdvupnigcoeymmjvrfpzfxcdgebankkveknwfeid"
             "rslwwodrkjuqhzcemtiuhztkzkqekzwyjtngvebcphvllmuywowcxhhpwldbswtqg"
             "pztbpfneqnbicojqbeayhtttxysbcapjjjcbzrxomwzdodlkexkfczdvxawvmxtdb"
             "vgoxkzodevpysshmeltcguffilungitzugwftrhcggeqbazzvcevpxgswsyjgrxdv"
             "vboqhojsxgfrcxbexelqakjjwwhvyztpeeppdtlwoepgbiiiiejmskrsfhqckylnt"
             "mokqjkxsmpokeiyrjvparyuqvhmladprksjgdsunrdnzsvmcryjkilcennxwtcqwr"
             "ahlblwmxdeaiymnhuowyjewamlwltxhvugyabpgpuupovplcokszcfbzbrnsjiiep"
             "avmphbhwqeobvmcmkamhhnehjcijiulaongtnifmtnczkmvwscbpfftnknvglqzyv"
             "vnqvkwlermvwmevmaafsgdtrwbenxaegpwfqhsuzdjzsyuevtcmoixeuugleeggeg"
             "qeaijqyfvzcoyttftwtxenklotbvuemyfcxppqgmlbfrfaipyjwgjagvdnxfxetuw"
             "dgzwfhvrdodlmfmjvvyuihofwbeeevvkfojtnruculvkbyzduanosjkiarrxohgvm"
             "bjptjqerkvwxzqcagtzwtfyjnkkzhbqyyeoiumpmjwhggbjhpllhbrprvdfnedeky"
             "ewkvptvxbkutrbokemjlpuseycavwghlucwionvncxrooiqwdrgwleohdtfywtsjs"
             "vjiiscmjhsadukxquyggusbqrnvcpcaxsfjtlhyzvlsyriexngujmjcsqfbovasxd"
             "lsrifpiyeztsjhvhgfxlckomwokkphdxyawbrlfwxvybhozfypnkwuwxcrbysbdxp"
             "jusiacvpxgvvzpipmhwxnsqiykbumreldpzmzjtigetybpyqpjjjxcbvuymgndzgy"
             "mnlactrkryuztyywlfbhdbuzxegyhtplgvxecsyuquyibjaklvyyejzcdbmunbqjc"
             "wwuqwmhakimbyqhmeidnyytssbdykaviozrryjkzwcwduvhsghdbzzhzdlmlwqdsa"
             "wgpyuodtrxrpfwkbrvvfqizwfaxvfyqlfkwsfyjkupanglhoraovksjfxizsqxalu"
             "xnfvkeosxrkbtlndasywtrlpyriahpvdtvdzspbtrbtmmlueaffmcrzzwqizrjvxm"
             "sbcgktvhccbvcjexcozstjszmutbdfitcghcrkiysqphttvspnnbbaqysigykkvkj"
             "onbmasybwfplcgatuaaqolgnvshjbxhikekgcgpaqjmmgprooqulpozplhsbmwxae"
             "vfshauwdufldpuwmdwanyordkoqwejplojhgcrdncsujmgwyerqwpgwpsyjnmidgk"
             "nhjgarrtkacjrsayjxjzkwfqrntxzqfvzgkipxnbpggbrdrlgzeszijqamprymztd"
             "ephnrkhwuvdmtkhxxcbooluhpbxczqlclkctsxnoncgrbmpqgphmuioniwijqwiwv"
             "kujvejvgaokhkvpmadmvemfibquudbgjysireuthfeweqdvrnzbzcmtbnvfifypwv"
             "fmoukansipogplmptuvxxnqserpykneutckaklajfvmpobejboaqqqxoiyruzlvkt"
             "krdftyspartvulvugsrgpcogaxacyukypvfkqtpnlgxvzyikoqrnmlxznlduqdzvc"
             "qwymwomgcqgshtnxqbxtlgqlqbprksbinitrhcyogdtnlqwrhicasapffnamlefuk"
             "uemlkgptohgwxcboaatvohltvltgwncfcwzudasslkxivuzwllemareqicbovfesn"
             "efpvvfvtazafrhimnzcvjipkwoapibiihvqkqxytgfpriqzatbvfrxgjjmqceoxfj"
             "fhgxruhoxbktvjeurzjnclbggoqhodxyemixyrnbsvkyfdjzfghktthbecrpbgchb"
             "reinnivoruppsahbybpefakwppavmdiypwsewthdkytdfsmltsadoolpwoohyobww"
             "tmbnfulgbctqdjiirruqfdtumkpasntctkbuqipkiuihpjwupaunfwpujorsddlst"
             "grmszcdhwlvjoakuvngzlvluzqgwfrckwlsmdbucjsgycygjapchxbsglbiplixox"
             "jwuimimqkugkrmukthcvqogjwusucgvxfohdxzqhtjgoeaxawuzuxytzuxukjyntw"
             "gtjuxidfpdoyhglijtbwcjzqzpmqbviexmlpbpxdamgqtuwlkxntpuccamqwjxzoj"
             "uftuafhoraiyaevtsbtxpnaliijpbjdcnbjytpfxyjzqznmfdbkyuesutothsfuif"
             "diekixsqkiwvefjempthjrhanrknzcjmdamvtyqwgsoygckoqynvslxlnrzzagbdv"
             "jeumkasmpqpaavurqrbkpsbmmoyeiadyosqaxrgonnyhgvtjiwwrnqdopmzkspblp"
             "yvugmsxpyiogljaupfnfrsaxjgxeybegttcpxgmunyntysxrpzjrcbusjniupvkga"
             "dbadjqkcjfiplpmqcjxoskfqrkrnxphxlotrkaqurpkqgmmuceqazkyslnmwzqhyp"
             "pzcivjyamecksbmcjtxgzgpamvnahglpmdnbgyifkfjcbhfthtqpvbefxadptobjw"
             "kathzdjsdfwscgjeqrqhisznkbxjvzvsxbnnuixvrfecjdkjkvbikpkdsajajfoov"
             "fdpergvlacrwzsfelcxsmqdbvchsfndlzxicugfjqgnxowzovcbojpmcjdddwhpmn"
             "uecxbutmplqvdgjgoitdjeqkjdzwlclrrsxosypfhdfivhixptrpwshwovifcjtwm"
             "pbcweyprxcixyimzglvwsequijfkuknvbxxskpurfsdowqabyqyyovmeisfdzlcts"
             "rdpcjfoyuwoohhuovwjhvynlohvktjfsliztelrpkrbqhnbhvyuhlrounjsfnmjkc"
             "vzaqcfltfkfhaqlbxnhacawcqxwxukkeuduozbjuahrkoamurqedkajvhorsaumlq"
             "dckzeimlfjprlmjosxpqpovawrehbyahadipcqzocyuwtaqigejwoyehldtmbihed"
             "uuxbcsflkrjfemewioxfaebklftheyvqnrgouztiaycsdljbxlaxtchgqsrnhaglc"
             "shxkmtximodplgpdgmtqkehltngwebfjpgbuiahtdjlgnzlwxogxovqkxqutovltt"
             "scypwxkwkdnzjlzidgswwypcyhavdzysygafjjjrareoipjlxizmykoiqbzjtfhmj"
             "dtcrruhjfttnuhdssfqrrorhzrwakykmaamuicdwjnlplesaticmfbhkluhpmusfc"
             "lopxsztywrxhspdtabdeedmmourbjzkozosedabfckguagpyhnxfyskvoxshowwnd"
             "uderazvpokiatozmxkjdunencurhyqblzmtktnlnwtmyedfkhosikqddarxgrqufd"
             "qvrzbpywgehgfdpqqegbbztwryxqrekasxtoiukqtbjswszhpzwszrenedupgkxni"
             "wdhmnbcqeuneyfpokffawzauzjqhubbsothphsqlbsplvaxpczazxaeidmueviyio"
             "oapbzyldqtyfhpdvurdwnotifepwcjmgwnlcavcsrnxffuazvfzmybzkoqsuslrmx"
             "fimrmagqozcswxskauexgprgiscxoytohuidtkphgdmdfpxrgnkotstboowwwgdpu"
             "xgdlowrgxwrfkyafgjwiogdbgwgivhpmfzmocavfusctgrcngyecehmctfjoiyikb"
             "kvnwldqgbldtswpcsvxvrkqgclrrsmvgjoopgxpsbqzbnmyzggrwakafsozhyvslo"
             "rcvasysyyrqdrrgdgrkwetcobjkadupescbikmspgbvrueiczcmaeuvdmeffysbjh"
             "ockrjtvvzyziujtxqvhpuawhzhdovkpnukpzdpfnyhzvyypywszhhqlpieicahwcs"
             "jimugaukgnwmkvefrywmyznjhxavrpqvayeqiiqshqcbajmhxfghswscvdfxybrpg"
             "orwuxawouwetkhtojhyrwofxjqignpmfozyfmdmvxglhtlebacvwmunelwibsybua"
             "hpctuosisxuougnmteezvpsahotgsokhplasgzpdfqwzwgmdistmdqqajznkdmezw"
             "xoafairfsocfabzvvqflboglglticygfmnovpdzjpcjdinhqapxtafqoihhyejtsx"
             "buvkdlovkabinlenyivzocgjgmyxkduzywyvkarxkqlbcitbxijvitoxpotuoqdyb"
             "nddedsmxhlbvixwpgmwhhkgwnggiwgylbjyixkregyciydkyeycpkisgidwxsnqmr"
             "ydkdcrgdmmsodybjkksfvbilqbleozkfptqpnqqqteeteikghzolrqswhpzrnzuba"
             "otefdwfowgqqtcotffoytzfpuayhmlmrxlimczpnrydfxsvusvpasawuhiicypfsv"
             "lpqttnoqtkqmkoavknugcafyrhdjkxfjzudwverorwywypbxjipzzvpqzzawzxkhy"
             "xuftngrhjrcunikeelwdalzmasbumuliuqmcmtoeucekddtgqgfhjzpoemrsxrnxe"
             "wvxccfsvaqboaktookyutekubmydvksjkzmgteiueylbwvldvxjnheapwsrbxekho"
             "zuljpovwkplrdvgtwigtsuqbnkxvgvumlxlhqlvkuwkzgrmxahvjsmaqhsuyebyez"
             "renpdxpvqgpdabtnuvjyuqauwdtpztimwkoajpumfuibvnkqkpxseobhvurmunulz"
             "tdtzxgedgdvznooxuqymbfqpseonxkvwticrrwestcqokuexsltjtpiwddgjwpzyp"
             "mzqpxaxbdgsiucxflfnehfyqlpvznzvxupulhkxlsuwjvwvvtmswdegcukbhkybbs"
             "cxohjlwsyhgpixqlheqbbfdpuwagungkbtvwyjbfcersvphlaxqrxnizjfwcczeqz"
             "eitrloqsenazbenwufcmqymjkuezvutbzggbnwwtvapcylsxpndfqgojbstqigtuy"
             "rxvdvmkabfyeekzsxtzmyuglffkifjccpfdlfefdkrjxnjruzjuhvrxrslgosalwf"
             "snxidgigsqismdkhgdfgatudwgfhrflxhrhgakrkenumnuamakfwxxdesmmmpcujc"
             "shboeetaesftggkrawsdrzuvlomkoladzcwxrvtuukssulkqcqfspwc")
      << endl;
}
