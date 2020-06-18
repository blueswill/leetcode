#include <string>

using std::string;

const string IPV4 = "IPv4";
const string IPV6 = "IPv6";
const string Neither = "Neither";

class Solution {
    private:
        string target;

        bool parse_ipv4(unsigned start, int cur) {
            if (start == target.size() + 1 && cur == 4)
                return true;
            if (start >= target.size() || cur >= 4 || target[start] < '0' || target[start] > '9')
                return false;
            if (target[start] == '0') {
                if (start + 1 == target.size() || target[start + 1] == '.')
                    return parse_ipv4(start + 2, cur + 1);
                return false;
            }
            int res = 0;
            while (start < target.size() && target[start] != '.' && res < 256) {
                res = res * 10 + target[start] - '0';
                ++start;
            }
            if (res >= 256)
                return false;
            return parse_ipv4(start + 1, cur + 1);
        }

        bool parse_ipv6(unsigned start, int cur) {
            if (start == target.size() + 1 && cur == 8)
                return true;
            if (start >= target.size() || cur >= 8 || target[start] == ':')
                return false;
            unsigned i;
            for (i = start; i < target.size() && i < start + 4 && target[i] != ':'; ++i) {
                if (!(target[i] >= 'a' && target[i] <= 'f' ||
                      target[i] >= 'A' && target[i] <= 'F' ||
                      target[i] >= '0' && target[i] <= '9'))
                    return false;
            }
            if (i < target.size() && target[i] != ':')
                return false;
            return parse_ipv6(i + 1, cur + 1);
        }
    public:
        string validIPAddress(string IP) {
            if (IP.size() < 7)
                return Neither;
            target = IP;
            if (IP[1] == '.' || IP[2] == '.' || IP[3] == '.') {
                if (parse_ipv4(0, 0))
                    return IPV4;
                return Neither;
            }
            if (parse_ipv6(0, 0))
                return IPV6;
            return Neither;
        }
};
