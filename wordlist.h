#ifndef WORDLIST_H
#define WORDLIST_H

#include <QStringList>

class WordList {
public:
    static QStringList getPossibleWords() {
        return QStringList{
            "apple", "grape", "peach", "melon", "berry",
            "table", "chair", "house", "plant", "flame",
            "river", "ocean", "cloud", "stone", "globe",
            "heart", "light", "watch", "story", "glass",
            "bread", "grill", "shelf", "drive", "bride",
            "flock", "crane", "glide", "sword", "piano",
            "gamer", "drink", "float", "climb", "crisp",
            "frame", "joint", "kneel", "laugh", "punch",
            "quest", "raise", "sheep", "trend", "whale",
            "whisk", "wheat", "torch", "trunk", "track",
            "weave", "wrist", "stamp", "twist", "storm",
            "pride", "quick", "match", "bliss", "crown",
            "dance", "dream", "frost", "green", "hatch",
            "image", "jewel", "knock", "layer", "liver",
            "month", "noble", "novel", "orbit", "paint",
            "quill", "roast", "score", "shine", "slice",
            "smile", "spark", "steak", "threw", "trend",
            "voice", "worry", "write", "yacht", "yield",
            "zebra", "urban", "vivid", "vowel", "xerox",
            "blame", "catch", "drill", "flute", "giant"
        };
    }
};

#endif // WORDLIST_H
