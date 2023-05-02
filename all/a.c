// Orianna is a great swimmer and she's going to a swimming competition this month and needs your help as she is highly
// paranoic about the results of the competition.

//     The competition consists in some sort of evaluations,
//     every judge makes a score and,
//     based on that score and the score of other contestants she will get a score belonging to her results,
//     those scores are final,
//     meaning that will not change in the competition.

//     Orianna
//       requires this
//     solution with urgency, she is getting evaluated on a lot of ways and she is very worried about her results,
//     so she wants to know what is the worst score from an evaluation A to other evaluation B inclusive.

//     Input The first line of the test data will start with an integer T representing the T test cases,
//     then, T cases will follow, each of the cases starts with two integers N and Q,
//     denoting the number of evaluations Orianna had, then, N integers will follow denoting the score on each
//     evaluation, after that, Q queries will begin, each query consist on two integers A and B.

//     Output You must output the string “Scenario #i :“,
//     a blank line and then the result of each query, remember,
//     Orianna is interested on the worst score from evaluation A to evaluation B inclusive.

//             Example Input : 2 5 3 1 2 3 4 5 1 5 1 3 2 4 5 3 1 -
//             2 - 4 3 -
//             5 1 5 1 3 2 4

//             Output : Scenario #1 : 1 1 2 Scenario #2 : -5 -
//                                                        4 - 4 Constraints 1 <=
//         T <= 100 Small input(30 %) :

//         1 <= N <= 1,
//     000 1 <= Q <= 1,
//     000 - 10 ^ 9 <= Ni <= 10 ^
//         9 1 <= A <= B <= N Large input(70 %) :

//             1 <= N <= 100,
//     000 1 <= Q <= 100, 000 - 10 ^ 9 <= Ni <= 10 ^ 9 1 <= A <= B <= N Solutions rejudged due to weak test cases.