#pragma once

#include <array>

#include <Generators/TokiPona/Lang/word.hpp>

namespace generators {
namespace tokipona {
namespace lang {

class Dictionary{
public:
    static const std::Array<Word, 100> adjectives = {
	Word(ADJ,	"ale",	"all"),
	Word(ADJ,	"anpa",	"humble"),
	Word(ADJ,	"ante",	"changed"),
	Word(ADJ,	"awen",	"safe"),
	Word(ADJ,	"ike",	"bad"),
	Word(ADJ,	"jaki",	"unclean"),
	Word(ADJ,	"jelo",	"yellow"),
	Word(ADJ,	"kama",	"coming"),
	Word(ADJ,	"ken",	"possible"),
	Word(ADJ,	"kepeken",	"to use with"),
	Word(ADJ,	"kule",	"colorful"),
	Word(ADJ,	"lape",	"sleeping"),
	Word(ADJ,	"laso",	"blue"),
	Word(ADJ,	"lete",	"cold"),
	Word(ADJ,	"lili",	"small"),
	Word(ADJ,	"loje",	"red"),
	Word(ADJ,	"lon",	"at"),
	Word(ADJ,	"moli",	"dead"),
	Word(ADJ,	"musi",	"recreational"),
	Word(ADJ,	"mute",	"many"),
	Word(ADJ,	"namako",	"new"),
	Word(ADJ,	"nasa",	"strange"),
	Word(ADJ,	"ni",	"that"),
	Word(ADJ,	"nimi",	"negative"),
	Word(ADJ,	"pakala",	"messed up"),
	Word(ADJ,	"pilin",	"feeling"),
	Word(ADJ,	"pimeja",	"black"),
	Word(ADJ,	"pini",	"finished"),
	Word(ADJ,	"pona",	"positive"),
	Word(ADJ,	"sama",	"same"),
	Word(ADJ,	"seli",	"fire"),
	Word(ADJ,	"suli",	"big"),
	Word(ADJ,	"suwi",	"sweet"),
	Word(ADJ,	"swei",	"divine"),
	Word(ADJ,	"taso",	"only"),
	Word(ADJ,	"tawa",	"moving"),
	Word(ADJ,	"walo",	"white"),
	Word(ADJ,	"wan",	"as one"),
	Word(ADJ,	"wawa",	"strong"),
	Word(ADJ,	"weka",	"absent"),
	Word(ADJ,	"wile",	"require")
    };
    static const std::array<Word, 100> nouns = {
	Word(NOUN,	"akesi",	"non-cude animal"),
	Word(NOUN,	"esun",	"market"),
	Word(NOUN,	"ijo",	"thing"),
	Word(NOUN,	"ilo",	"tool"),
	Word(NOUN,	"insa",	"inside"),
	Word(NOUN,	"jan",	"person"),
	Word(NOUN,	"kala",	"water animal"),
	Word(NOUN,	"kasi",	"plant"),
	Word(NOUN,	"kili",	"edible plant"),
	Word(NOUN,	"kiwen",	"hard object"),
	Word(NOUN,	"ko",	"clay"),
	Word(NOUN,	"kon",	"air"),
	Word(NOUN,	"kulupu",	"tribe"),
	Word(NOUN,	"kute",	"ear"),
	Word(NOUN,	"lawa",	"head"),
	Word(NOUN,	"len",	"fabric"),
	Word(NOUN,	"linja",	"rope"),
	Word(NOUN,	"lipu",	"document"),
	Word(NOUN,	"luka",	"arm"),
	Word(NOUN,	"lukin",	"eye"),
	Word(NOUN,	"lupa",	"orifice"),
	Word(NOUN,	"ma",	"earth"),
	Word(NOUN,	"mama",	"progenitor"),
	Word(NOUN,	"mani",	"money"),
	Word(NOUN,	"meli",	"female"),
	Word(NOUN,	"mi",	"we"),
	Word(NOUN,	"mije",	"male"),
	Word(NOUN,	"monsi",	"behind"),
	Word(NOUN,	"mun",	"star"),
	Word(NOUN,	"nanpa",	"number"),
	Word(NOUN,	"nasin",	"way"),
	Word(NOUN,	"nena",	"protuberance"),
	Word(NOUN,	"nimi",	"word"),
	Word(NOUN,	"noka",	"leg"),
	Word(NOUN,	"ona",	"they"),
	Word(NOUN,	"palisa",	"long hard thing"),
	Word(NOUN,	"pan",	"cereal"),
	Word(NOUN,	"pilin",	"heart"),
	Word(NOUN,	"pipi",	"insect"),
	Word(NOUN,	"poka",	"side"),
	Word(NOUN,	"selo",	"outer layer"),
	Word(NOUN,	"sijelo",	"body"),
	Word(NOUN,	"sike",	"round thing"),
	Word(NOUN,	"sina",	"you"),
	Word(NOUN,	"sinpin",	"front"),
	Word(NOUN,	"sitelen",	"representation"),
	Word(NOUN,	"soweli",	"land animal"),
	Word(NOUN,	"suno",	"light"),
	Word(NOUN,	"supa",	"horizontal surface"),
	Word(NOUN,	"swei",	"highest part"),
	Word(NOUN,	"telo",	"liquid"),
	Word(NOUN,	"tenpo",	"time"),
	Word(NOUN,	"tomo",	"buliding"),
	Word(NOUN,	"uta",	"mouth"),
	Word(NOUN,	"waso",	"flying creature")
    };
    static const std::array<Word,100> particles = {
	Word(PART,	"a",	"ah!"),
	Word(PART,	"anu",	"or"),
	Word(PART,	"e",	""),
	Word(PART,	"en",	""),
	Word(PART,	"la",	""),
	Word(PART,	"li",	"word"),
	Word(PART,	"mu",	"[animal noise]"),
	Word(PART,	"o",	"oh!"),
	Word(PART,	"pi",	"of"),
	Word(PART,	"seme",	"what?"),
	Word(PART,	"taso",	"but"),
	Word(PREP,	"tan",	"from"),
	Word(PREP,	"tawa",	"toward"),
    };
    static const std::array<Word, 100> verbs = {
	Word(VERB,	"alasa",	"hunt"),
	Word(VERB,	"jo",	"carry"),
	Word(VERB,	"kalama",	"produce sound"),
	Word(VERB,	"moku",	"consume"),
	Word(VERB,	"oko",	"see"),
	Word(VERB,	"olin",	"love"),
	Word(VERB,	"open",	"open"),
	Word(VERB,	"pali",	"do"),
	Word(VERB,	"pana",	"give"),
	Word(VERB,	"sona",	"wise about"),
	Word(VERB,	"toki",	"say"),
	Word(VERB,	"unpa",	"shag"),
	Word(VERB,	"utala",	"challenge"),
    };


    Dictionary();

};

} //lang
} //tokipona
} //generators
