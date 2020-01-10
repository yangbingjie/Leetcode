//
//  main.cpp
//  482_licenseKeyFormatting
//
//  Created by Bella Yang on 2020/1/9.
//  Copyright © 2020 Bella Yang. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        int len = K;
        string R(S.size() + int(S.size() / K),' ');
        int index = 0;
        for (int i = int(S.size() - 1); i >= 0; --i) {
            if (S[i] == '-') {
                continue;
            }else{
                if (len == 0) {
                    R[index] = '-';
                    index++;
                    len = K;
                }
                if (isalpha(S[i]) && S[i] > 'Z') {
                    S[i] -= 'a' - 'A';
                }
                R[index] = S[i];
                index++;
                len--;
            }
        }
        reverse(R.begin(), R.end());
        int begin = 0;
        while (begin < R.size()) {
            if (R[begin] != ' ') {
                break;
            }
            begin++;
        }
        return R.substr(begin);
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s;
    cout << s.licenseKeyFormatting("btiG-NPt-qVJQUBMlKmyWpUVKCOsICDRi-IIJUkblUS-c-OYacySVxTm-Acz-aWAUbfenj-bGFNRSOQnsMighw-x-NGC-UMKmMSPBGNbBvK-h-w-HAhsvSBBOkRzVTEdnauPm-ZdbcwZiArbLH-G-OdDNjTZpkqWNgqVTf-JT-PClYeM-FBWy-Ydxlkd-KEJwumA-kXoaGMfLRFwlkYC-AZkx-quclJd-aMczmEqX-lVRbAWTBIUKUvucm-fTRcKGJxJHmyy-dPxCKdBW-awuOWUnGFPSc-vZxl-QZNRDo-CSXLhNRC-v-j-sdVYTAm-Ahz-JraaFq-KJmlFgAQ-tHgf-rL-iWBbZRVccJoAJzBtCPJLDdgSiMAGFYZoeCmF-nILvGrwi-vEer-NvBy-HR-edIkVPTGfAyTGx-EykeYwFTTLeQPxpqMHlvEeWYFm-Wi-ZyVsjXdgw-DMmAgar-DO-nmvijIPuDKT-KJdRzrYWgMnI-RWOsppfA-PzJGzzlrgtLYFwzsAKRXAbaIIIb-JdGFW-GmKhYv-n-eFKtaCirJhYm-gevsjXb-sDj-ep-QgE-tZNbsBgPfOKuUCPF-VFIBbtg-jhvyedctnSCiUDopRKzCIBAuazx-FY-fkWlDYWJaMPdRXKVw-qWhtFPPNP-ZBqSBcnPJ-n-fKKctt-cG-SpxxuUmfsIjU-BLVVIw-DqaTuyMZZgYPXDCQBuBYfwaLIEvsxec-BHSk-imBhLgGmlcbQB-wJEam-XV-QDO-bWiFsyGPJd-F-gmuWRBpkfOdUBIgYWMdYDLpMKLEmBemIaFk-cvsIT-yaxcILsFSOkmwgotTEFlpBrShZj-qyrMZKWY-iXiHoywGPGR-DH-MnQNI-rNkfXrKhAwMseqdr-rOG-jyFptM-At-Rx-KCLNazBFBZMLNoC-Ua-SGCa-qlQ-XsjLPvNrBSsvEULeANqmGwhCBhmHeOcqSA-oKtbT-AeqMcvNtWuI", 1
)<<endl;
    return 0;
}
