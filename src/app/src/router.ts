// Vue Router 4
import {createRouter, createWebHashHistory} from "vue-router";
// @ts-ignore
import {Main} from "./components/layout/components/Main/index.ts";
// @ts-ignore
import {Home} from "./components/page/index.ts";
// @ts-ignore
import {Room} from "./components/layout/index.ts"

export default createRouter({
    history: createWebHashHistory(),
    routes: [{
        path: '',
        components: {'Room': Home}
    }, {
        path: '/group/:id',
        name: 'switchGroup',
        components: {'Room': Room, 'Content': Home},
        children: [{
            path: '',
            components: {'Content': Home}
        }, {
            path: '/group/:id/channel',
            name: 'switchChannel',
            components: {'Content': Main}
        }]
    }]
});
