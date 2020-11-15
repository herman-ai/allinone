#include <vector>
#include <string>
#include <iostream>

using namespace std;

bool solve_helper(vector<string>& words, string word, bool my_turn);

bool solve(vector<string>& words) {
    return solve_helper(words, "", true);
}

vector<string> is_valid(vector<string>& words, string new_word) {
    vector<string> new_words;
    for (string w: words) {
            if (w.find(new_word) == 0) {
                new_words.push_back(w);
            }
        }
        return new_words;
}

bool solve_helper(vector<string>& words, string word, bool my_turn) {
    
    if (find(words.begin(), words.end(), word) != words.end()) {
        if (my_turn) {
            return true;
        } else {
            return false;
        }
    }
    bool me_wins = my_turn? false: true;
    
    vector<char> valid_moves;
    int move_num = word.size();
    for (string w: words) {
        if (move_num < w.size()) {
            valid_moves.push_back(w[move_num]);
        }
    }
    
    for (char c : valid_moves) {
        string new_word = word+c;
        vector<string> new_words = is_valid(words, new_word);
        if (new_words.size()==0) {
            continue;
        }
        if (!my_turn) {
            me_wins = me_wins && solve_helper(new_words, new_word, !my_turn);
            if (!me_wins) {
                return false;
            }
        } else {
            me_wins = me_wins || solve_helper(new_words, new_word, !my_turn);
        }
    }
    return me_wins;
}

int main() {
    vector<string> words = {"nsaski", "lqnutpl", "ddwrgu", "ycqxvvuvlh", "tpxzn", "xdxwin", "yjopufn", "zcoezzt", "nvwhy", "ikhpxqzn", "hkuwuidraq", "msmjww", "qhxuuxbmdj", "gdqkmpqel", "zikczkysel", "icddre", "rfjnrv", "ynfqlht", "ksxvehfey", "satcsyi", "rgljqbk", "fvtvwyacd", "qkvktilnsp", "swygd", "dbfnjnhsn", "jrfildkrfh", "gdwnmeq", "oznqxoor", "gfntbavjrs", "hjncvien", "eclyio", "ggdhw", "hqijpgjwxb", "aozqwmc", "dzvesnc", "yvuyog", "hpgwneljm", "chwrqwku", "ztbnsvugee", "odpimh", "ejjhv", "vnemjow", "kaumkmgwk", "dwxejmuuj", "jkjqwdbd", "uucgjvj", "tbsehozme", "eseqjtwdk", "mlmhiabrog", "gsawguw", "bdypvsn", "lyupsu", "vynlh", "dwnjjhfz", "fvyqfpxajg", "epyvakrkl", "vmmot", "ucwxgu", "jqszxndr", "pwymbluam", "epsgtfw", "ttibuw", "ruvcqhtfqe", "buvjpfr", "ycjjo", "kakkazqjr", "fwblevzw", "cqlqswmk", "fwseyoyu", "ckdnz", "nkwrqvolj", "txuepcv", "rcald", "nmmipslihy", "yaswhxhlt", "fymyvu", "sdxlr", "ypqsok", "bzirn", "rdbxep", "zlvya", "moiauqbi", "lonjqp", "uonsl", "owpkb", "avfbjtcftb", "loiykwllz", "dbnoydl", "potwpxxvm", "wmgufgqu", "pjhabrfqeb", "lqbeg", "ebuoi", "erfvbbiwv", "aalrc", "pcvuz", "scuderaci", "mqetc", "asswljmy", "wwdchewra", "psynq", "aurbzuo", "qvqtqiljye", "jemrfwix", "ehbfkhp", "tnaurkors", "jfptwel", "grndvbdol", "taplvenk", "qdediyx", "homqeuavz", "fdyypy", "lxemd", "mgibt", "zussgjfj", "swhsagf", "jryafvje", "wztvoo", "kabdvjkxgd", "zkzycsuwc", "pbvdfvnkx", "ajckfs", "zqhyam", "izwpolic", "zpvtsnp", "ixtel", "sshbdsn", "gbmanm", "gwlyvxfiww", "pjtvr", "phbydmp", "bhmjxae", "ztccek", "abcugpj", "uggawn", "ljloouggtf", "twnhsaxqy", "lzmeuf", "xuyrha", "atowd", "yvzyjjot", "pnnxuuwx", "rlzydxvdf", "wulici", "smrrl", "xfvpaxmcax", "ggiafggwek", "cxswdtktdy", "hhqqgj", "dxuzljdt", "xladmbcam", "ixnrrcsnof", "rhuvl", "afxvu", "jrzcgz", "ubkdkxsb", "fpivees", "nssojxr", "zapwyyzi", "tyifhjptmq", "ovgesw", "pazugtnasu", "ztljnuwomt", "layir", "mlriux", "zhddfvwm", "nqagnl", "bhjrchrqa", "hgzpvsqec", "chaborpw", "lpxco", "jyuwqoex", "vfglphlt", "mhegdyz", "hiiakmax", "gfgnw", "yingflmbyz", "ahzlsl", "qdftjrtkh", "bcwsysi", "dqugdo", "puapm", "gnult", "oresms", "ytzcjq", "ndbolyh", "irjnsh", "igagt", "jexgop", "wmqtccon", "feosxhvzwj", "jdobknikp", "banjqmgglr", "onisn", "xvwvoa", "jhuxzzd", "qpxbzlmg", "xxvgsd", "yuuomvvst", "goscwcflw", "hkhfqaaogh", "dvwzd", "geovvo", "oossgr", "xbmegiy", "jwrmuawin", "otnscxc", "mynnnt", "hriefxh", "xnkmg", "ltuvdoqb", "yxkcbsg", "jwrnxn", "jpswui", "yzmlr", "xjmue", "xlpco", "lezoo", "ufwul", "ehzlgblor", "hbicjmwvfy", "llhdu", "cpqxjcgeh", "gnmgookjr", "ntrdrz", "yikwjgp", "ujmaxhwqny", "tvkzrc", "qkposc", "mwuvgf", "qzjkongsgy", "oylspzx", "girzo", "hiawqx", "eqpklwcffb", "vtmgoqud", "vocxus", "vovuwaasq", "rrxmcjxm", "bgecebv", "ezlvsarvvm", "ovixrcatbr", "fftpwyhyhh", "rbavveguqf", "pcpjxikp", "pxjrghl", "ftlneney", "pdojellwvp", "rpktupj", "wxwikwdzmt", "pqkmvyc", "nfpzvwnagl", "svnnau", "rsjohruggx", "cvhequbv", "ofizh", "idkknavt", "itlgveuzqq", "ckldyc", "chwuw", "tqofwpre", "hzomrlom", "srdnwq", "yztsbjoewt", "wxbwxqgp", "efdedpzgd", "krqoe", "tmaoazdso", "qmrcwcl", "xqthqgns", "chkywn", "hkfug", "qfucq", "smylg", "iwtymeayea", "ikbynefe", "glxhyfxsu", "ayldnu", "pbuzaxy", "lgmmpzm", "toatdpte", "sxffvsjion", "tjnaow", "lnewm", "sjlphshdq", "crhcl", "tqpegl", "xpejakbr", "ncdhytnrm", "kfjtgrb", "fvrqhgis", "zpfikwdbc", "rjumizhlqg", "ntvbbcetri", "fxeyg", "vszvtvwhvc", "gtaivuz", "xpyutfyw", "isjxuxa", "unwknq", "iiuedro", "affyvfswk", "uasowd", "iwgjnewwt", "knvka", "puxxtbj", "cszbxvymgt", "fqchdtwhy", "bgwrluoz", "vftbxdru", "tgikbp", "fkicwruad", "ypsadn", "penvzabjeu", "ohwykwqc", "cpbkew", "pngtzyvfo", "bubewtzulw", "thpsrhccb", "nhsphpgacj", "rhkvzyth", "ekvgy", "ehxucpzhc", "ilsbg", "anqaskomw", "ogugaq", "fyksjbrkd", "ytmvrkcd", "vinoj", "bjekxxye", "axncnbwbze", "rqmjkgw", "udemmndvii", "onmgejilm", "vxqekuys", "cxypx", "vrdvkqy", "hypcxpxl", "ekhnetviz", "jansuy", "ikmsizxje", "bqrtkuky", "mlumaa", "silhjgfgoc", "zxqdjxrv", "rekgwpet", "qxcovmke", "mssrqx", "celepiij", "gihvptkjmq", "ueiysqpqod", "qzkgn", "ligjrzb", "unzpxr", "nipclgge", "kzvhzsxeaq", "cfjeetsvls", "mmjfhdwvi", "eejnd", "ikcyrqkb", "arlrcq", "eidkdevs", "mfnqnilacc", "hskltj", "cgutytrcjr", "eeqxcopyny", "hkxwnzmj", "cmpejr", "uoxqdkao", "bcctr", "gjnphg", "zbkeecmai", "ienxiqx", "xrgoydapq", "wgnopinq", "rjqlc", "dtfmtlriu", "jpssw", "lbqmiynv", "pqrglufvys", "uudinyckf", "rwwervc", "cnbvprsojm", "edomo", "qpiyb", "splrct", "cynsp", "fdoumzh", "eusgoeno", "npitliyh", "lgkfpo", "vveze", "ihprtkn", "sujsumv", "aodemwem", "vecdmucc", "dbrnbnqhyn", "ukmlxcw", "sskeeeq", "kwxcm", "jhoimcjtbi", "ccyqvc", "dcfnmkgjfe", "xcsbiynm", "wtygtfmcae", "ovkrgqbwf", "sgyzjqx", "zppmy", "huyand", "bjfjkjno", "vqshkxd", "eycvh", "eczewz", "idpjakthjd", "uncylvjd", "aeonvrwafk", "bfjqgtfsl", "dzjsaho", "nyehz", "ppnlesblj", "npjyxe", "ltljxcgp", "wnugu", "ffcvfud", "eillhegjm", "zizetr", "bsmdkg", "colbgmeyjx", "aaqxnfcak", "hsiiq", "ywwmrgc", "hxqfuw", "kjuksmq", "sfevdltqi", "zllnsok", "vtxzeam"};

    bool me_wins = solve(words);
    cout << "Can I win? " << me_wins << endl;
}