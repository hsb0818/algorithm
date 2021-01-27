// TC: O(NLogN)
// SC: O(N)
function solution(genres, plays) {
    const genresMap = genres
        .reduce((genresMap, genre, idx) => {
            genresMap[idx] = genre;
            return genresMap;
        }, {});
    plays = plays.map((play, idx) => ({ play, idx }));

    const check = {};
    return Array.from(plays
        .reduce((bestGenreMap, { play, idx }) => {
            const genre = genresMap[idx];
            const e = bestGenreMap.get(genre);
            if (e) {
                e.ids.push({ idx, play });
                e.totalPlay += play;
            } else {
                bestGenreMap.set(genre, { ids: [{ idx, play }], totalPlay: play });
            }

            return bestGenreMap;
        }, new Map()), ([genre, play]) => ({ genre, play }))
        .sort((a, b) => b.play.totalPlay - a.play.totalPlay)
        .map((e) => {
            e.play.ids.sort((a, b) => b.play - a.play);
            return e;
        })
        .reduce(((bestAlbums, { play: { ids } }) => {
            bestAlbums = [...bestAlbums, ...ids.slice(0, 2).map(({ idx }) => idx)];
            return bestAlbums;
        }), []);
}

console.log(solution(["classic", "pop", "classic", "classic", "pop"], [500, 600, 150, 800, 2500]));