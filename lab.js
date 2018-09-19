var str;
str = "Enter    string";

function lastCharacter(str)
{
    console.log(str.charAt(str.length - 1));
}

function outLastCharacter(str)
{
    console.log(str.substring(0, str.length - 1));
}

function reverse(str)
{
    console.log(str.split("").reverse().join(""));
}

function aloneSpace(str)
{
    console.log(str.replace(/\s+/g,' ').trim());
}

lastCharacter(str);
outLastCharacter(str);
reverse(str);
aloneSpace(str);