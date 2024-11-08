# Challenges
- One of my biggest challenges for this deliverable was building type constraints from the SIP AST nodes. A big challenge was figuring out what the type rules are for each SIP feature, especially the Array Expression, as it was important to know where to put constraints on each component of the array expression.
- One problem that I was stuck on for a long time was when I tried to run type constraint unit tests in TypeConstraintCollectTest. It was an issue of unification of types which I figured out was a problem with not adding the new TipTypes inside the doMatch method in TipCons.  

My approach to testing and achieving high code coverage is by making sure that all constraints will be handled by introducing the new SIP features and adding some complexity into the unit tests. Then, I extended unit tests in assignability checking and the two TipTypes: TipBool and TipArr to ensure code coverage in both the weeding pass and the type system.

