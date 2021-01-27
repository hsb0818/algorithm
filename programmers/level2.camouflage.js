// TC: O(N) : Loop O(N), Map O(1)
// SC: O(N) : Map O(N)
function solution(clothes) {
    const clothMap = clothes.reduce((clothMap, [c, type]) => {
        clothMap.set(type, parseNumber(clothMap.get(type)) + 1);
        return clothMap;
    }, new Map());

    let answer = 1;
    for (const [type, cnt] of clothMap) {
        answer *= cnt + 1;
    }

    return answer - 1;
}

function parseNumber(x) {
    return !x ? 0 : Number(x);
}

console.log(solution([['yellow_hat', 'headgear'], ['blue_sunglasses', 'eyewear'], ['green_turban', 'headgear']]));
//console.log(solution([["crow_mask", "face"], ["blue_sunglasses", "face"], ["smoky_makeup", "face"]]));