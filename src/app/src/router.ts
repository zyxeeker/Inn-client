// Vue Router 4
import {createRouter, createWebHashHistory} from "vue-router";
// @ts-ignore
import {Main} from "./components/layout/components/Main/index.ts";
// @ts-ignore
import {Home} from "./components/page/index.ts";
// @ts-ignore
import {Group} from "./components/layout/index.ts"

export default createRouter({
    history: createWebHashHistory(),
    routes: [{
        path: '',
        components: {Group: Home}
    }, {
        path: '',
        name: 'switchGroup',
        components: {Group: Group},
        children: [{
            path: '',
            name: 'switchChannel',
            components: {Main: Main}
        }]
    }
    ]
});
