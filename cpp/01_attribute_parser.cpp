#include <iostream>
#include <map>
#include <sstream>
#include <regex>

using namespace std;
/*
Developer:     Ruslan Arifullin
Date:          APR 28 2018

DIFFICULTY:    Medium
               
PROBLEM:       We have defined our own markup language HRML. In HRML, each element consists
               of a starting and ending tag, and there are attributes associated with each tag. 
               Only starting tags can have attributes. We can call an attribute by referencing 
               the tag, followed by a tilde, '~' and the name of the attribute. The tags may 
               also be nested.
               The opening tags follow the format:
                    <tag-name attribute1-name = "value1" attribute2-name = "value2" ... >
               The closing tags follow the format:
                    < /tag-name >
               For example:
                    <tag1 value = "HelloWorld">
                    <tag2 name = "Name1">
                    </tag2>
                    </tag1>

               The attributes are referenced as:
                    tag1~value  
                    tag1.tag2~name

               You are given the source code in HRML format consisting of N lines. You have to answer Q
               queries. Each query asks you to print the value of the attribute specified. Print "Not
               Found!" if there isn't any such attribute.
               
               
                ---- testcase 1  ------
                4 3
                <tag1 value = "HelloWorld">
                <tag2 name = "Name1">
                </tag2>
                </tag1>
                tag1.tag2~name
                tag1~name
                tag1~value
                
                ---- output 1 ------
                123
                43.4
                hello
                Not Found!
                Hello
                Universe!
                World!
                New
                Not Found!
                Not Found!
                34
                9.845
                Not Found!
                Not Found!
                
                ---- testcase 2  ------
                10 10
                <a value = "GoodVal">
                <b value = "BadVal" size = "10">
                </b>
                <c height = "auto">
                <d size = "3">
                <e strength = "2">
                </e>
                </d>
                </c>
                </a>
                a~value
                b~value
                a.b~size
                a.b~value
                a.b.c~height
                a.c~height
                a.d.e~strength
                a.c.d.e~strength
                d~sze
                a.c.d~size
                ---- result ----
                GoodVal
                Not Found!
                10
                BadVal
                Not Found!
                auto
                Not Found!
                2
                Not Found!
                3
                
                
                ----- testcase 3 -------
                16 14
                <tag1 v1 = "123" v2 = "43.4" v3 = "hello">
                </tag1>
                <tag2 v4 = "v2" name = "Tag2">
                <tag3 v1 = "Hello" v2 = "World!">
                </tag3>
                <tag4 v1 = "Hello" v2 = "Universe!">
                </tag4>
                </tag2>
                <tag5>
                <tag7 new_val = "New">
                </tag7>
                </tag5>
                <tag6>
                <tag8 intval = "34" floatval = "9.845">
                </tag8>
                </tag6>
                tag1~v1
                tag1~v2
                tag1~v3
                tag4~v2
                tag2.tag4~v1
                tag2.tag4~v2
                tag2.tag3~v2
                tag5.tag7~new_val
                tag5~new_val
                tag7~new_val
                tag6.tag8~intval
                tag6.tag8~floatval
                tag6.tag8~val
                tag8~intval
                
                ---- output ----
                123
                43.4
                hello
                Not Found!
                Hello
                Universe!
                World!
                New
                Not Found!
                Not Found!
                34
                9.845
                Not Found!
                Not Found!
                
                tag1.tag2.tag3~ v2 : World!
                tag1.tag2.tag3~v1 : Hello
                tag1.tag2.tag4~ v2 : Universe!
                tag1.tag2.tag4~v1 : Hello
                tag1.tag2~ name : Tag2
                tag1.tag2~v4 : v2
                tag1.tag5.tag7~new_val : New
                tag1.tag6.tag8~ floatval : 9.845
                tag1.tag6.tag8~intval : 34
                tag1~ v2 : 43.4
                tag1~ v3 : hello
                tag1~v1 : 123
*/


void strictRootTag(string &inputString, string &rootTag) {
    string closeTag = inputString.substr(2, inputString.length() - 3);

    string tagName;
    // if closeTag is in the head of rootTag
    if (rootTag.find(closeTag) == 0) {
        // remove closeTag
        rootTag.replace(0, closeTag.length(), "");

        // if a dot is left after removal - it should be removed
        if (rootTag.find(".") == 0)
            rootTag.replace(0, 1, "");
    }
    else if (rootTag.find(".") != -1) {
        // if closeTag is located in the middle or in the end...
        tagName = "." + inputString.substr(2, closeTag.length());
        rootTag.replace(rootTag.length() - tagName.length(), tagName.length(), "");
    }
    else {
        //if closeTag is an only part of  rootTag
        tagName = inputString.substr(2, closeTag.length());
        rootTag.replace(rootTag.length(), tagName.length(), "");
    }
}

void expandRootTag(string &inputString, string &rootTag) {
    // removing angle brakets in the head and the tail
    inputString = inputString.substr(1, (inputString.size() - 2));

    size_t endOfTag = inputString.find(" ");
    string tag = inputString.substr(0, endOfTag);

    // exclude tag out of the string
    inputString = inputString.substr(endOfTag + 1, inputString.length() - (endOfTag + 1));

    // joining parental and dependant tags
    stringstream streamTags;
    streamTags << rootTag << ((rootTag != "") ? "." : "") << tag;

    rootTag = streamTags.str();
}

void parseFormattedString(string &inputString, string &rootTag, map<string, string> &parsed) {

        //  -- tags ---
        if (inputString.substr(1,1) == "/"){
            // removing tag and exit
            strictRootTag(inputString, rootTag);
            return;
        }

        expandRootTag(inputString, rootTag);

        //parsing inputString and populating map
        regex keyValExpr("([a-zA-Z0-9_]+) = \"([^\"]*)\"");
        auto string_begin = sregex_iterator(inputString.begin(), inputString.end(), keyValExpr);
        auto string_end = sregex_iterator();

        for (sregex_iterator iter  = string_begin; iter != string_end; ++iter) {
            smatch match = *iter;
            string match_str = match.str();

            smatch matchInsideLoop;
            regex_search(match_str, matchInsideLoop, keyValExpr);

            string key = rootTag + "~" + matchInsideLoop[1].str();
            string value = matchInsideLoop[2].str();
            parsed.insert(pair<string, string>(key, value));
        }

    return ;
}

int main() {
    string params;
    getline(cin, params);

    int spacePos = params.find(" ", 0);

    int firstCounter = atoi(params.substr(0, spacePos).c_str());
    int secondCounter = atoi(params.substr(spacePos, (params.length() - spacePos)).c_str());

    string hrml_string;
    string tag_string = "";

    map<string, string> parsed_string = {};
    for (unsigned int i = 0; i < firstCounter; ++i) {
        getline(cin, hrml_string);
        parseFormattedString(hrml_string, tag_string, parsed_string);
    }

    string query_string;
    for (unsigned int i = 0; i < secondCounter; ++i) {
        getline(cin, query_string);
        cout << ((parsed_string[query_string].length() == 0) ? "Not Found!" : parsed_string[query_string]) << endl << endl;
    }

    return 0;
}