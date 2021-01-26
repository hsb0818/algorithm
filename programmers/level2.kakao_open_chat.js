/**
 * Level 2
 * [Kakao:오픈채팅방]
 * TC: O(N) - Map: Hash table
 * SC: O(N)
 */

function solution(record) {
    const chats = [];
    const userMap = new Map();
    for (const row of record) {
        const [cmd, uid, nickname] = row.split(' ');

        if (['Enter', 'Change'].includes(cmd)) {
            userMap.set(uid, nickname);

            if (cmd === 'Enter')
                chats.push({ uid, cmd: 'e' });
        } else if (cmd === 'Leave') {
            chats.push({ uid, cmd: 'l' });
        }
    }

    return chats.map(({ uid, cmd }) => {
        const action = (cmd === 'e') ? '님이 들어왔습니다.' : '님이 나갔습니다.';
        return `${userMap.get(uid)}${action}`;
    });
}

console.log(solution(["Enter uid1234 Muzi", "Enter uid4567 Prodo", "Leave uid1234", "Enter uid1234 Prodo", "Change uid4567 Ryan"]));