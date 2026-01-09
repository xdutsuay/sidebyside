class PriorityQueue {
    constructor() {
        this.queue = [];
    }

    push(value) {
        this.queue.push(value);
        this.sort();
    }

    pop() {
        return this.queue.shift();
    }

    sort() {
        this.queue.sort((a, b) => a[0] - b[0]);
    }
}

class BiDirectionalDijkstra {
    constructor(graphForward, graphBackward) {
        this.graphForward = graphForward;
        this.graphBackward = graphBackward;
        this.parentForward = {};
        this.parentBackward = {};
        this.costForward = { [Object.keys(this.graphForward)[0]]: 0 };
        this.costBackward = { [Object.keys(this.graphBackward)[0]]: 0 };
    }

    calculateCost(v, visitedForward, visitedBackward) {
        for (const [nxt, d] of Object.entries(this.graphForward[v])) {
            if (!visitedForward.has(nxt)) {
                const oldCostF = this.costForward[nxt] || Infinity;
                const newCostF = this.costForward[v] + d;

                if (newCostF < oldCostF) {
                    this.queue.push([newCostF, nxt]);
                    this.costForward[nxt] = newCostF;
                    this.parentForward[nxt] = v;
                }

                if (!this.graphBackward[v]) continue;
                const [nxtBwd, cstBwd] = Object.entries(this.graphBackward[v])[0];
                if (cstBwd) {
                    const newDistance = this.costForward[v] + d + cstBwd;

                    if (newDistance < this.costBackward[nxtBwd]) {
                        this.queue.push([newDistance, nxtBwd]);
                        this.costBackward[nxtBwd] = newDistance;
                        this.parentBackward[nxtBwd] = v;
                    }
                }

                if (!visitedForward.has(nxt)) return;
            }
        }

        return this.costForward[v];
    }

    run(source, destination) {
        let shortestPathDistance = -1;

        const queueForward = new PriorityQueue();
        const queueBackward = new PriorityQueue();

        queueForward.push([0, source]);
        queueBackward.push([0, destination]);

        if (source === destination) return 0;

        while (!queueForward.isEmpty() && !queueBackward.isEmpty()) {
            let [_, vFwd] = queueForward.pop();
            const visitedForward = new Set([vFwd]);
            shortestDistance = this.calculateCost(vFwd, visitedForward, new Set());

            let [_, vBwd] = queueBackward.pop();
            const visitedBackward = new Set([vBwd]);

            shortestDistance = this.calculateCost(vBwd, visitedBackward, visitedForward);

            if (this.costForward[vFwd] + this.costBackward[vBwd] >= shortestDistance) break;

            if (shortestDistance !== Infinity) {
                shortestPathDistance = shortestDistance;
            }
        }

        return shortestPathDistance;
    }
}

const graphForward = {
    "B": [["C", 1]],
    "C": [["D", 1]],
    "D": [["F", 1]],
    "E": [["B", 1], ["G", 2]],
    "F": [],
    "G": [["F", 1]],
};
const graphBackward = {
    "B": [["E", 1]],
    "C": [["B", 1]],
    "D": [["C", 1]],
    "F": [["D", 1], ["G", 1]],
    "E": [[null, Infinity]],
    "G": [["E", 2]],
};

const biDirectionalDijkstra = new BiDirectionalDijkstra(graphForward, graphBackward);
console.log(biDirectionalDijkstra.run("E", "F")); // Output: 3