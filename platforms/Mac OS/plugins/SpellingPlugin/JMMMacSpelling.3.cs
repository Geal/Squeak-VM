'From Squeak3.8 of ''5 May 2005'' [latest update: #6665] on 15 February 2006 at 3:41:19 pm'!"Change Set:		JMMMacSpellingDate:			15 June 2005Author:			johnmci@smalltalkconsulting.comMac Spelling, interface to os-x spelling interface, allows you to check a utf-16 string for errors, set ignored words, change dictionary used, etc"!Object subclass: #MacSpellingInterface	instanceVariableNames: ''	classVariableNames: 'Tag'	poolDictionaries: ''	category: 'Multilingual-Editor'!Smalltalk renameClassNamed: #MacServicesInterfaceTest as: #MacSpellingInterfaceTest!!MacSpellingInterfaceTest commentStamp: 'JMM 6/15/2005 16:53' prior: 0!Mac spelling checking interface. Test casesuses SpelllingPluginbyJohn M McIntoshjohnmci@smalltalkconsulting.comJune 15th 2005!!MacSpellingInterface methodsFor: 'converter' stamp: 'JMM 6/15/2005 09:59'!byteStringToUTF16: bytes	^bytes asString convertFromWithConverter: (TextConverter newForEncoding: 'utf-16').! !!MacSpellingInterface methodsFor: 'converter' stamp: 'JMM 6/15/2005 09:38'!unknownToUTF16: candidate	^candidate convertToWithConverter: (TextConverter newForEncoding: 'utf-16').! !!MacSpellingInterface methodsFor: 'guesses' stamp: 'JMM 6/15/2005 09:44'!getGuesses: aString	| size collection word utf16 toGuess |		toGuess := self unknownToUTF16: aString.	size := self primGetGuessesForWordListLength: toGuess withTag: Tag.	collection := OrderedCollection new: size.	1 to: size do: [:i |		word := self primGetGuessesForWordwithTag: Tag at: i.		utf16 := self byteStringToUTF16: word.			collection add: utf16].	^collection! !!MacSpellingInterface methodsFor: 'ignored words' stamp: 'JMM 6/15/2005 09:36'!getIgnoredWords	| size collection word utf16 |		size := self primGetIgnoredWordsListLengthWithTag: Tag.	size isZero ifTrue: [^OrderedCollection new].	collection := OrderedCollection new: size.	1 to: size do: [:i |		word := self primGetIgnoredWordWithTag: Tag at: i.		utf16 := self byteStringToUTF16: word.		collection add: utf16].	^collection! !!MacSpellingInterface methodsFor: 'ignored words' stamp: 'JMM 6/15/2005 09:40'!setIgnoredWords: anArray	"AnArray is unicode 16bit values"	| utf16 |	self primSetIgnoredWordsListLength: anArray size withTag: Tag.	1 to: anArray size  do: [:i | 		utf16 _ self unknownToUTF16: (anArray at: i).		self primSetIgnoredWords: utf16 withTag: Tag at: i].! !!MacSpellingInterface methodsFor: 'ignored words' stamp: 'JMM 6/15/2005 09:39'!setIgnoredWord: aString	"unicode32 is unicode value"	| utf16 |	utf16 := self unknownToUTF16: aString.	self primSetNewIgnoredWord: utf16 withTag: Tag! !!MacSpellingInterface methodsFor: 'initialize-release' stamp: 'JMM 6/14/2005 17:59'!initialize	Tag := self primGetUniqueSpellingTag.! !!MacSpellingInterface methodsFor: 'language' stamp: 'JMM 6/14/2005 18:37'!getLanguageString	"ByteString , ie english"	^self primGetLanguage! !!MacSpellingInterface methodsFor: 'language' stamp: 'JMM 6/14/2005 18:21'!setLanguageString: aString	"ByteString , ie english"	self primSetLanguage: aString! !!MacSpellingInterface methodsFor: 'spelling' stamp: 'JMM 6/15/2005 09:43'!checkSpellingOf: aString startingAt: anInteger	| results utf16 |	utf16 := self unknownToUTF16: aString.	results := self primCheckSpelling: utf16 startingAt: anInteger.	^results! !!MacSpellingInterface methodsFor: 'system primitives' stamp: 'JMM 6/14/2005 18:18'!primCheckSpelling: aString startingAt: anInteger	<primitive:'primitiveCheckSpelling' module: 'SpellingPlugin'>! !!MacSpellingInterface methodsFor: 'system primitives' stamp: 'JMM 6/14/2005 18:14'!primGetGuessesForWordListLength: data withTag: aTag	<primitive:'primitiveGetGuessesForWordListLength' module: 'SpellingPlugin'>! !!MacSpellingInterface methodsFor: 'system primitives' stamp: 'JMM 6/14/2005 18:14'!primGetGuessesForWordwithTag: aTag at: index	<primitive:'primitiveGetGuessesForWordwithTag' module: 'SpellingPlugin'>! !!MacSpellingInterface methodsFor: 'system primitives' stamp: 'JMM 6/14/2005 18:10'!primGetIgnoredWordsListLengthWithTag: aTag	<primitive:'primitiveGetIgnoredWordsListLengthWithTag' module: 'SpellingPlugin'>! !!MacSpellingInterface methodsFor: 'system primitives' stamp: 'JMM 6/14/2005 18:12'!primGetIgnoredWordWithTag: Tag at: i	<primitive:'primitiveGetIgnoredWordWithTag' module: 'SpellingPlugin'>! !!MacSpellingInterface methodsFor: 'system primitives' stamp: 'JMM 6/14/2005 18:07'!primGetLanguage	<primitive:'primitiveGetLanguage' module: 'SpellingPlugin'>! !!MacSpellingInterface methodsFor: 'system primitives' stamp: 'JMM 6/14/2005 17:59'!primGetUniqueSpellingTag	<primitive:'primitiveGetUniqueSpellingTag' module: 'SpellingPlugin'>! !!MacSpellingInterface methodsFor: 'system primitives' stamp: 'JMM 6/14/2005 18:07'!primSetIgnoredWordsListLength: anArray withTag: Tag	<primitive:'primitiveSetIgnoredWordsListLength' module: 'SpellingPlugin'>! !!MacSpellingInterface methodsFor: 'system primitives' stamp: 'JMM 6/14/2005 18:04'!primSetIgnoredWords: string withTag: Tag at: i	<primitive:'primitiveSetIgnoredWords' module: 'SpellingPlugin'>! !!MacSpellingInterface methodsFor: 'system primitives' stamp: 'JMM 6/14/2005 18:08'!primSetLanguage: aString	<primitive:'primitiveSetLanguage' module: 'SpellingPlugin'>! !!MacSpellingInterface methodsFor: 'system primitives' stamp: 'JMM 6/14/2005 18:15'!primSetNewIgnoredWord: aString withTag: Tag	<primitive:'primitiveSetNewIgnoredWord' module: 'SpellingPlugin'>! !!MacSpellingInterfaceTest methodsFor: 'running' stamp: 'JMM 6/15/2005 15:44'!testAGuess	| s chk |	s := spelling getGuesses: 'ackbar2'.	self should: [s isEmpty].	s := spelling getGuesses: 'recieve'.	chk := s collect: [:e | e asString].	self should: [chk includes: 'receive'].	self should: [chk size > 1].	! !!MacSpellingInterfaceTest methodsFor: 'running' stamp: 'JMM 6/15/2005 09:50'!testATag	| s |	s := spelling primGetUniqueSpellingTag.	self should: [s isNumber].	self should: [s > 0].	! !!MacSpellingInterfaceTest methodsFor: 'running' stamp: 'JMM 6/15/2005 09:53'!testGetIgnoredWords	| s |	s := spelling getIgnoredWords.	self should: [s isCollection].	! !!MacSpellingInterfaceTest methodsFor: 'running' stamp: 'JMM 6/15/2005 12:24'!testGetSetLanguageString	| l remember |	l := spelling getLanguageString.	self should: [l size > 0].	remember _ l.	spelling setLanguageString: l.	l := spelling getLanguageString.	self should: [l size > 0].	self should: [remember = l].	! !!MacSpellingInterfaceTest methodsFor: 'running' stamp: 'JMM 6/15/2005 16:56'!testSetIgnoredWord	|  w1 i2 i2strings w2 w3 |	w1 := self waitASecondRollOver.	spelling setIgnoredWord: w1.	i2 := spelling getIgnoredWords.	i2strings := i2 collect: [:e | e asString].	self should: [i2strings includes: w1].	w2 := self waitASecondRollOver.	spelling setIgnoredWord: w2.	i2 := spelling getIgnoredWords.	i2strings := i2 collect: [:e | e asString].	self should: [i2strings includes: w1].	self should: [i2strings includes: w2].		spelling setIgnoredWords: (OrderedCollection new).	w3 := self waitASecondRollOver.	spelling setIgnoredWord: w3.	i2 := spelling getIgnoredWords.	self should: [i2 size = 1].	i2strings := i2 collect: [:e | e asString].	self should: [i2strings includes: w3].! !!MacSpellingInterfaceTest methodsFor: 'running' stamp: 'JMM 6/15/2005 16:38'!testSetIgnoredWords	|  w1 i i2 i3 i3strings i1strings i2strings |	i := spelling getIgnoredWords.	i isEmpty ifTrue: [		spelling setIgnoredWords: (OrderedCollection with: 'ackbar').		i2 := spelling getIgnoredWords.		self should: [i2 size = 1].		self should: [(i2 at: 1) asString = 'ackbar'].		spelling setIgnoredWords: (OrderedCollection with: 'ackbar' with: 'ackbar2').		i3 := spelling getIgnoredWords.		self should: [i3 size = 2].		i3strings := i3 collect: [:e | e asString].		self should: [i3strings includes: 'ackbar'].		self should: [i3strings includes: 'ackbar2']		].	i := spelling getIgnoredWords.	w1 := self waitASecondRollOver.	i1strings := i collect: [:e | e asString].	i1strings add: w1.	spelling setIgnoredWords: i1strings.	i2 := spelling getIgnoredWords.	i2strings := i2 collect: [:e | e asString].	self should: [i2strings includes: w1].	spelling setIgnoredWords: (OrderedCollection new).	i := spelling getIgnoredWords.	self should: [i size = 0].! !!MacSpellingInterfaceTest methodsFor: 'running' stamp: 'JMM 6/15/2005 16:48'!testSpelling	| s i |	spelling setIgnoredWords: (OrderedCollection new).	i := spelling getIgnoredWords.	self should: [i size = 0].	s := spelling checkSpellingOf: 'recieve' startingAt: 1.	self should: [(s at: 1) = 1].	self should: [(s at: 2) = 7].	s := spelling checkSpellingOf: 'receive' startingAt: 1.	self should: [(s at: 2) = 0].	spelling setIgnoredWord: 'recieve'.	s := spelling checkSpellingOf: 'recieve' startingAt: 1.	self should: [(s at: 2) = 0].	spelling setIgnoredWords: (OrderedCollection new).	s := spelling checkSpellingOf: 'recieve' startingAt: 1.	self should: [(s at: 1) = 1].	self should: [(s at: 2) = 7].	! !!MacSpellingInterfaceTest methodsFor: 'running' stamp: 'JMM 6/15/2005 16:59'!testSpellingOffset	| s i |	spelling setIgnoredWords: (OrderedCollection new).	i := spelling getIgnoredWords.	self should: [i size = 0].	s := spelling checkSpellingOf: 'too recieve' startingAt: 1.	self should: [(s at: 1) = 5].	self should: [(s at: 2) = 7].	s := spelling checkSpellingOf: 'too more recieve' startingAt: 1.	self should: [(s at: 1) = 10].	self should: [(s at: 2) = 7].	s := spelling checkSpellingOf: 'toox more recieve' startingAt: 1.	self should: [(s at: 1) = 1].	self should: [(s at: 2) = 4].	s := spelling checkSpellingOf: 'toox more recieve' startingAt: 6.	self should: [(s at: 1) = 11].	self should: [(s at: 2) = 7].! !!MacSpellingInterfaceTest methodsFor: 'utility' stamp: 'JMM 6/15/2005 14:16'!waitASecondRollOver	| now duration |	now := Time  millisecondClockValue.	[duration := (Time  millisecondClockValue) - now.	duration > 0]		whileFalse: [(Delay forMilliseconds: 10) wait].	^Time  millisecondClockValue printString! !!MacSpellingInterfaceTest methodsFor: 'initialize-release' stamp: 'JMM 6/15/2005 09:48'!setUp	spelling _ MacSpellingInterface new.! !!MacSpellingInterface reorganize!('converter' byteStringToUTF16: unknownToUTF16:)('guesses' getGuesses:)('ignored words' getIgnoredWords setIgnoredWords: setIgnoredWord:)('initialize-release' initialize)('language' getLanguageString setLanguageString:)('spelling' checkSpellingOf:startingAt:)('system primitives' primCheckSpelling:startingAt: primGetGuessesForWordListLength:withTag: primGetGuessesForWordwithTag:at: primGetIgnoredWordsListLengthWithTag: primGetIgnoredWordWithTag:at: primGetLanguage primGetUniqueSpellingTag primSetIgnoredWordsListLength:withTag: primSetIgnoredWords:withTag:at: primSetLanguage: primSetNewIgnoredWord:withTag:)!