// Vue Router 4
import {createRouter, createWebHashHistory} from "vue-router";
// @ts-ignore
import {Main} from "./components/layout/components/Main/index.ts";
// @ts-ignore
import {Home} from "./components/page/index.ts";

export default createRouter({
    history: createWebHashHistory(),
    routes: [{
        path: '/',
        // name: 'Home',
        components: {Main: Home},
        props: {Main: true}
    }, {
        path: '/',
        name: 'toContentHeader',
        components: {Main: Main},
        props: {Main: true}
    }
    ]
});