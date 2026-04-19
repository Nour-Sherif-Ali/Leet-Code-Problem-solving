/**
 * @param {Generator} generator
 * @return {[Function, Promise]}
 */
function cancellable(generator) {
    let resolvePromise;
    let rejectPromise;
    let cancelled = false;
    let promise = new Promise((resolve, reject) => {
        resolvePromise = resolve;
        rejectPromise = reject;
    })

    const g = generator;

    function run(nextValue, shouldThrow) {
        let value;
        let done;
        try {
            const res = shouldThrow ? g.throw(nextValue) : g.next(nextValue);
            value = res.value;
            done = res.done;
        } catch (err) {
            rejectPromise(err);
            return;
        }
        if (done) {
            resolvePromise(value);
            return;
        }
        value.then(val => {
            if (cancelled) {
                return;
            }
            run(val);
        }).catch((err) => {
            run(err, true)
        })
    }

    run();

    return [
        () => {
            cancelled = true;
            try {
                const val = g.throw('Cancelled');
                resolvePromise(val.value);
            } catch (err) {
                rejectPromise(err);    
            }
        },
        promise,
    ]
};

/**
 * function* tasks() {
 *   const val = yield new Promise(resolve => resolve(2 + 2));
 *   yield new Promise(resolve => setTimeout(resolve, 100));
 *   return val + 1;
 * }
 * const [cancel, promise] = cancellable(tasks());
 * setTimeout(cancel, 50);
 * promise.catch(console.log); // logs "Cancelled" at t=50ms
 */

/**
 * function* tasks() {
 *   const val = yield new Promise(resolve => resolve(2 + 2));
 *   yield new Promise(resolve => setTimeout(resolve, 100));
 *   return val + 1;
 * }
 * const [cancel, promise] = cancellable(tasks());
 * setTimeout(cancel, 50);
 * promise.catch(console.log); // logs "Cancelled" at t=50ms
 */